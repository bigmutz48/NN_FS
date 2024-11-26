#include "NN.cuh"
#include <string>
#include <iostream>
#include <cuda_runtime.h>
#include <cstdlib>
#include <stdexcept>


__host__ void NN::check_success_cudaMalloc(cudaError_t cuda_call_return_value){} // end check_success_cudaMalloc()
__host__ bool NN::populate_nn_from_folder(std::string folder_path){} // end populate_nn_from_folder()
__device__ void NN::run_forward_prop_next_layer(){} // end run_forward_prop_next_layer()
__global__ void NN::run_test_one_example(float* inputs, int number_of_inputs){} // end run_test_one_example()


__global__ void NN::run_training_one_example(float* inputs, int number_of_inputs){

	// see if the network is setup for training 
	if(!this->is_ready_for_training){
		this-> set_up_nn_for_training();
	}


} // end run_training_one_example()
__host__ void NN::save_nn(std::string output_file_name){} // end save_nn


__host__ void NN::set_up_nn_for_training(){

	if(this->is_ready_for_training){
		throw std::runtime_error("NN::set_up_nn_for_training was called but is_ready_for_training was true");
	}

	//////// SETTING UP NN FOR TRAINING //////////
	
	// allocate memory for weights gradients
	cudaError_t cudaCallReturnValue = cudaMalloc((void** )&this->hidden_layers_weights_ptr_ptr_ptr,
			this->qty_hidden_layers * sizeof(float**));
	check_success_cudaMalloc(cudaCallReturnValue);

	for(int i = 0 ; i < this->qty_hidden_layers ; i++){
		
		
		cudaError_t cudaCallReturnValue = cudaMalloc((void** )&this->hidden_layers_weights_ptr_ptr_ptr[i],
				qty_neurons_per_hidden_layer * sizeof(float*));
		check_success_cudaMalloc(cudaCallReturnValue);


		}

		for(int j = 0 ; j < this->qty_neurons_per_hidden_layer ; j++){

			// special case for first layer
			if(i = 0){
			cudaError_t cudaCallReturnValue = cudaMalloc((void** )&this->hidden_layers_weights_ptr_ptr_ptr[i][j],
					this->qty_neurons_input_layer * sizeof(float));
			check_success_cudaMalloc(cudaCallReturnValue);

			}else{
			cudaError_t cudaCallReturnValue = cudaMalloc((void** )&this->hidden_layers_weights_ptr_ptr_ptr[i][j],
					this->qty_neurons_per_hidden_layer * sizeof(float));
			check_success_cudaMalloc(cudaCallReturnValue);
			}
		}

	}




	// once we have set up the nn then we need to set is_ready_for_training to true 
	this->is_ready_for_training = true;

} // end set_up_nn_for_training()



} // end nn_ready_to_setup

// 2nd helper for initialize_new_nn
__host__ void initialize_biases(){





} // end of initialize_biases


// helper for initialize_new_nn()
__host__ void initialize_weights(){



} // end initialize_weights_and_biases()


// use He intialization to initialize one layers of weights
__host__ void He_initialization_for_weights_one_layer(float* weights_ptr, int num_weights){

} // end He_initialization_for_weights_one_layer

__host__ void NN::initialize_new_nn(){

	

	// first allocate memory 
	this->allocate_memory_on_device();	


	// now we need to set all the weights to random values
	this->initialize_weights();
	
	// then initialize the biases
	this->initialize_biases();

} // end initialize_new_nn()

// when all the parameters are set for the NN dimensions we can allocate memory for them
__host__ void NN::allocate_memory_on_device(){

		//////////////// VALIDATE REQUEST ////////////////////////  
		
		if(this->qty_neurons_input_layer < 1){
throw std::runtime_error("NN::allocate_memory_on_device was called but qty_neurons_input_layer is less than 1");
		}

		if(this->qty_neurons_per_hidden_layer < 1){
throw std::runtime_error("NN::allocate_memory_on_device was called but qty_neurons_per_hidden_layer was less than 1");
		}

		if(this->qty_neurons_output_layer < 1){
throw std::runtime_error("NN::allocate_memory_on_device was called but qty_neurons_output_layer was less than zero");		
		}

		if(this->qty_hidden_layers < 1){
throw std::runtime_error("NN::allocate_memory_on_device was called but qty_hidden_layers was less than 1");
		}
		//////// END VALIDATE REQUEST //////////////////////


		//////////// ALLOCATE MEMORY ON GPU //////////////// 
		
		// NEURONS // 

		// set up input layer 
		cudaError_t cudaMallocCall = cudaMalloc((void** )&(this->input_layer_neurons_ptr), 
				this->qty_neurons_input_layer * sizeof(float));
		
		// make sure the allocation was succsessful
		this->check_success_cudaMalloc(cudaMallocCall);

		// set up the hidden layers main array 
		cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_neurons_ptr_ptr), 
				this->qty_hidden_layers * sizeof(float*));
		this->check_success_cudaMalloc(cudaMallocCall);

		// allocate space for each of the hidden layer arrays 
		for( int i = 0 ; i < qty_hidden_layers ; i++){
			
			// allocate space for the current hidden layer array 
			cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_neurons_ptr_ptr[i]), 
					this->qty_neurons_per_hidden_layer * sizeof(float));
			this->check_success_cudaMalloc(cudaMallocCall);
		}

		// set up output layer neurons 
		cudaMallocCall = cudaMalloc((void** )&(this->output_layer_neurons_ptr),
				this->qty_neurons_output_layer * sizeof(float));
		check_success_cudaMalloc(cudaMallocCall);

		// WEIGHTS //  
		
		// allocate for the big array where each index represents the weights matrix for a single hidden layer
		cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_weights_ptr_ptr_ptr),
				this->qty_hidden_layers * sizeof(float**));
		check_success_cudaMalloc(cudaMallocCall);

		// allocate for each hidden layer 
		for(int i = 0 ; i < qty_hidden_layers ; i++){
			
			// if we are looking at the first hidden layer it is a special case 
			if(i == 0){
				cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_weights_ptr_ptr_ptr[i]),
						this->qty_neurons_per_hidden_layer * sizeof(float*));
				check_success_cudaMalloc(cudaMallocCall);
				
				// then go allocate memory for the weights vector of each neuron in the 
				// first hidden layer 
				for(int j = 0 ; j < this->qty_neurons_per_hidden_layer ; j++){
					
					// at each neuron allocate for a vector of floats the length of 
					// the number of input neurons 
					cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_weights_ptr_ptr_ptr[i][j]),
							this->qty_neurons_input_layer * sizeof(float));
					check_success_cudaMalloc(cudaMallocCall);
				}


			} else {

			// allocate memory for this layers main array 
			cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_weights_ptr_ptr_ptr[i]), 
							this->qty_neurons_per_hidden_layer * sizeof(float*));
			check_success_cudaMalloc(cudaMallocCall);

			// allocate memory for each vector in this hidden layers main array 
			for(int j = 0 ; j < this->qty_neurons_per_hidden_layer ; j++){
				cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_weights_ptr_ptr_ptr[i][j]), 
							this->qty_neurons_per_hidden_layer * sizeof(float));
				check_success_cudaMalloc(cudaMallocCall);


			}



		}
		} // end of hidden layer memory allocation for loop 

		// allocate for the output layer 
		cudaMallocCall = cudaMalloc((void** )&(this->output_layer_weights_ptr_ptr),
				this->qty_neurons_per_hidden_layer * sizeof(float*));
		check_success_cudaMalloc(cudaMallocCall);

		// now allocate memory for the weights vector of each neuron in the output layer 
		for(int i = 0 ; i < this->qty_neurons_output_layer ; i++){

			cudaMallocCall = cudaMalloc((void** )&(this->output_layer_weights_ptr_ptr[i]), 
					this->qty_neurons_per_hidden_layer * sizeof(float));
			check_success_cudaMalloc(cudaMallocCall);

		}



		// BIASES // 
		
		// allocate for hidden layers 
		cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_biases_ptr_ptr), // main array
				this->qty_hidden_layers * sizeof(float*));
		check_success_cudaMalloc(cudaMallocCall);
		for(int i = 0 ; i < this->qty_hidden_layers ; i++){ // array for each hidden layer 
			cudaMallocCall = cudaMalloc((void** )&(this->hidden_layers_biases_ptr_ptr[i]),
					this->qty_neurons_per_hidden_layer * sizeof(float));
			check_success_cudaMalloc(cudaMallocCall);
		}

		// for output layer 
		cudaMallocCall = cudaMalloc((void** )&(this->output_layer_biases_ptr), 
				this->qty_neurons_output_layer * sizeof(float));



} // end of allocate_memory_on_device()


