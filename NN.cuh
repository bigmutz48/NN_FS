#ifndef NN_CUH
#define NN_CUH


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

		////// NEURAL NET ///////

		// input neurons array 
		float* input_layer_ptr;

		// contains pointers that each point to a hidden layer array 
		float** hidden_layers_ptr_ptr;

		// output layer 
		float* output_layer_ptr;


		// check if a cudaMalloc call was succsessful or not
		// -> this function should crash the program and provide a detailed error 
		// message if the cuda call is unsuccessful
		void check_success_cudaMalloc(cudaError_t cuda_call_return_value);


	public:
	
	__host__ NN(	
			// neurons per layer
			int qty_neurons_input_layer,
			int qty_neurons_per_hidden_layer,
			int qty_neurons_output_layer,
			
			// quantity of hidden layers 
			int qty_hidden_layers,

			// init parameters 
			int init_b_value

			){
		
		// set all the metadata
		this->qty_neurons_input_layer = qty_neurons_input_layer;
		this->qty_neurons_per_hidden_layer = qty_neurons_per_hidden_layer;
		this->qty_neurons_output_layer = qty_neurons_output_layer;
		this->qty_hidden_layers = qty_hidden_layers;
		this->init_b_value = init_b_value;

		//////////// SET UP NN ON DEVICE //////////////// 
		
		// set up input layer 
		cudaError_t cudaMallocCall = cudaMalloc((void** )&input_layer_ptr, qty_neurons_input_layer * sizeof(float));
		
		// make sure the allocation was succsessful
		check_success_cudaMalloc(cudaMallocCall);


				}

};






#endif
