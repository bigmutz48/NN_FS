#ifndef NN_CUH
#define NN_CUH

#include <string>


/*
				### NN OBJECT CLASS ###
	Basically this class is going to be the Neural Net itself
	-> neural net initialization parameters will be passed through the pci bus from the ram
	to the gpu and the neural net will be built on the gpu 
	-> from this point on the only data that should be transfered from the host to the device through
	the pci bus should be training data examples host -> device and for testing the result of a test host <- device


 */ 

class NN{

	private:
		////// METADATA ///////
	
		// neurons per layer
		int qty_neurons_input_layer;
		int qty_neurons_per_hidden_layer;
		int qty_neurons_output_layer;

		// number of hidden layers
		int qty_hidden_layers;

		// initialization parameters
		float init_b_value;


		// training info 
		std::string training_equation;
		int num_training_examples;


		//// NETWORK STATUS FLAGS ///// 
		bool is_ready_for_training = false;


		////// NEURAL NET ITSELF /////////////////////////////////////////////////////

		// NEURONS // 	

		// input neurons array 
		float* input_layer_ptr;

		// contains pointers that each point to a hidden layer array 
		float** hidden_layers_neurons_ptr_ptr;

		// output layer 
		float* output_layer_neurons_ptr;


		// WEIGHTS // 
		
		// hidden layer weights
		float*** hidden_layers_weights_ptr_ptr_ptr;

		// output layer weights 
		float** output_layer_weights_ptr_ptr;

		// BIASES // 
		
		// hidden layers 
		float** hidden_layers_biases_ptr_ptr;

		// output layer 
		float* output_layer_biases_ptr;

		///// ADDITIONAL STRUCTURES IF TRAINING IS BEING DONE ////////////////

		// to hold gradient values for weights and biases 
		float*** gradient_for_weights_ptr_ptr_ptr;
		float** gradient_for_biases_ptr_ptr;

		//////////////// PRIVATE MISCELLANEOUS FUNCTIONS /////////////////////
		
		// check if a cudaMalloc call was succsessful or not
		// -> this function should crash the program and provide a detailed error 
		// message if the cuda call is unsuccessful
		__host__ void check_success_cudaMalloc(cudaError_t cuda_call_return_value);


		// reinitialize a previously created nn by populating this nn with data
		// from files in a special folder
		__host__ bool populate_nn_from_folder(std::string folder_path);

		// allocate device memory for our program
		__host__ void allocate_memory_on_device();

		// initialize a blank nn
		__host__ void initialize_new_nn();

		// helper for initialize_new_nn()
		__host__ void initialize_weights();

		// 2nd helper for initialize_new_nn
		__host__ void initialize_biases();

		// use He intialization to initialize one layers of weights
		__host__ void He_initialization_for_weights_one_layer(float* weights_ptr, int num_weights);


		// set the network up for training 
		// -> allocate memory for the gradient of the weights and of the biases
		__host__ void set_up_nn_for_training();

		
		/////////////// PRIVATE NEURAL NET OPERATION FUNCTIONS //////////////////

	

		// takes no input
		__device__ void run_forward_prop_next_layer();


	public:
	
		__host__ NN(	
				// true if this is a new NN 
				// and false if we are loading an NN from files
				bool is_new = true,


				/////////// IF MAKING A NEW NN ////////////////

				// neurons per layer
				int qty_neurons_input_layer = 0,
				int qty_neurons_per_hidden_layer = 0,
				int qty_neurons_output_layer = 0,
				
				// quantity of hidden layers 
				int qty_hidden_layers = 0,

				// init parameters 
				int init_b_value = 0,
				
				///// IF REINITIALIZING A PREVIOUSLY CREATED NN /////
				std::string nn_folder_path = ""
				){
			
			

			if(is_new){

				// set all the metadata
				this->qty_neurons_input_layer = qty_neurons_input_layer;
				this->qty_neurons_per_hidden_layer = qty_neurons_per_hidden_layer;
				this->qty_neurons_output_layer = qty_neurons_output_layer;
				this->qty_hidden_layers = qty_hidden_layers;
				this->init_b_value = init_b_value;
				
				// then initialize 
				initialize_new_nn();
			}else{
				populate_nn_from_folder(nn_folder_path);
			}

					} // end of NN constructor 
		

		////////////////////// PUBLIC FUNCTIONS FOR NN OPERATION //////////////////////////////

		// takes an example and returns the output of the NN for that example 
		__global__ void run_test_one_example(float* inputs, int number_of_inputs);

		// runs a training example:
		// -> runs forward prop and then backprop for a piece of training data
		__global__ void run_training_one_example(float* inputs, int number_of_inputs);


		// this creates a folder with all the data about this NN object
		__host__ void save_nn(std::string output_file_name);


		// network will need a couple of extra things set up if training 
		// is going to occur
		// -> memory to keep track of the cost gradient with respect to each weight and bias 
		__host__ void prepare_network_for_training();
};






#endif
