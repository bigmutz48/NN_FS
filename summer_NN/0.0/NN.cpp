#include "NN.hpp"

	
NN(int qty_inputs, int qty_hidden_layer_density, int qty_hidden_layer);
	: this->qty_inputs(qty_inputs), this->qty_hidden_layer(qty_hidden_layer),
	this->qty_hidden_layer_density(qty_hidden_layer_density) 
{

//////////////////////////// ACTIVATIONS //////////////////////////////////
NN_activations = std::vector<std::vector<double>>(qty_hidden_layer + 2);

// input 

NN_activations[0] = std::vector<double>(qty_inputs);

// hidden layers
for ( int i = 1 ; i < qty_hidden_layer + 2 ; i++){
NN_activations[i] = std::vector<double>(qty_hidden_layer_density);

}



// for output 
NN_activations[qty_hidden_layer + 2] = std::vector<double>(1, 0);


// weights

std::vector<std::vector<std::vector<double>>> NN_weights;


// biases

std::vector<std::vector<double>> NN_biases;


//////////////////// WEIGHTS ////////////////////////////////////////////////

NN_weights = std::vector<std::vector<std::vector<double>>>(qty_hidden_layer + 1);


// exclude i = 0 and include qty_hidden_layer + 2
for (int i = 0 ; i < qty_hidden_layer + 1 ; i++){
if(i == 0){
	NN_weights[i] = std::vector<std::vector<double>>(qty_hidden_layer_density, qty_inputs, 1); 
} else if( i == qty_hidden_layer + 1){
	NN_weights[i] = std::vector<std::vector<double>>(1 , qty_hidden_layer_density, 1);
} else {
	NN_weights[i] = std::vector<std::vector<double>>(qty_hidden_layer_density, qty_hidden_layer_density, 1);

}
}




///////////////////////////////// BIASES ///////////////////////////////////

for(int i = 1 ; i < qty_hidden_layer + 2 ; i++){
	NN_biases[i - 1] = std::vector<double>(NN_activations[i].size();
}





} // end constructor

// default deconstructor
NN::~NN(){}




bool NN::run_forward_prop(coord my_coord){
	// from input through all hidden layers
	for ( int i = 0 ; i < this->qty_hidden_layer ; i++){
		// for each nueron in this layer 
		for ( int j = 0 ; j < this->qty_hidden_layer_density ; j++){
		NN_activations[i + 1][j] = math.ReLU(math.dot_product(NN_activations[i], NN_weights[i]) + NN_biases[i]); 

		}


	}
	// from last hidden layer to ouput
	for (int i = 0 ; i < 1 ; i++){
	
		// set the last element of NN_activations equal to the second to last NN_activations dotted with the last NN_weights
	NN_activations[this->qty_hidden_layer + 1][i] 
	= math.ReLU(math.dot_product(NN_activations[qty_hidden_layer], NN_weights[qty_hidden_layer]) + NN_biases[qty_hidden_layer]);
	}

}


void NN::run_training_on_data(data my_data){
	// make the infrastructure to hold gradient and derivative values
	std::vector<std::vector<gradient_coord>> NN_gradients(this->qty_hidden_layer + 1);


////////////////// TRAINING FOR EACH COORDINATE /////////////////////////
	
	// for each training coord
	for  ( int i = 0 ; i < my_data.num_data_points ; i++){
	
	coord my_coord = my_data.test_data[i];
	// run the forward prop
	NN::run_forward_prop(my_coord);


		// for each layer in the network that has weights and biases
		for (int j = this->qty_hidden_layer ; j >= 0 ; j--){
			
			if ( j == this->qty_hidden_layer){

			// for each neuron in the current layer
			for (int k = 0 ; k < this->NN_activations[i + 1].size() ; k++){
			
			// set the cost with respect the activation 
			NN_gradients[i][j].coord_map["dc_da"] = 

			// set the activation with respect to the raw input 
			NN_gradients[i][j].coord_map["da_dz"] = 

			// partial of z with respect to this neurons bias
			NN_gradients[i][j].coord_map["dz_db"] = 


			// do this for all weights that are associated with this neuron
				for (int f = 0 ; f < this->NN_activations[i] ; f++){

				NN_gradients[i][j].coord_map["dz_dw" + std::to_string(f)] = 

				}



			}


		} // end output layer writing 

		// for everything else
		else{

		
		
			// for each neuron in the current layer
			for (int k = 0 ; k < this->NN_activations[i + 1].size() ; k++){
			
			// set the cost with respect the activation 
			
			/*
			 *	COMPUTATION FOR DC_DA: 
			 *	-> trying to calculate for the layer i at neuron j
			 *	-> if i+1 is the output layer then i is the last hidden layer etc.
			 *	DC/DA(j,i) = DC/DA(?,i+1) * DA(?,i+1)/DZ(?,i+1) * DZ(?,i+1)/DA(j,i)
			 *	 ... this should work but what value for ?
			 *
			 *
			 *	val = DC/DA(j,i) = 0;
			 *	for (int j = 0 ; j < neurons[i+1].size() ; j++){
			 *	
			 *	
			 *	// sum them all up ... don't divide	  
			 *	val += DC/DA(?,i+1) * DA(?,i+1)/DZ(?,i+1) * DZ(?,i+1)/DA(j,i);
			 * 	
			 *	}
			 *
			 *
			 *
			 *
			 *
			 */

			

			////////////////////// CALCULATE PARTIALS ///////////////////////////////

			double val_dc_da = 0;
			double val_da_dz = 0;
			double val_dz_db = 0;



			// val_dc_da for layer i 
				// loop over all nuerons in the i + 1 layer 
				for (int z = 0 ; z < NN_activations[i].size() ; z++){
				val_dc_da += 
				NN_gradients[i+1][z]["dc_da"] * 
				NN_gradients[i+1][z]["da_dz"] *
				NN_weights[i+1][z][j];
				
				// tricky -- dz(z, i+1)/da(j, i) is equal to NN_weights[i+1][z][j]
		
		
				}

			// val_da_dz
				// if the z value for the forward pass of this neuron was >0 then val_da_dz
				// = 1 ... else val_da_dz = 0
				if (NN_activations[j+1][k] == 0){
					val_da_dz = 0;
				} else{
					val_da_dz = 1;
				}
			// val_dz_db
				val_dz_db = 1;


			//////////////////// WRITE PARTIALS ///////////////////////////////

			NN_gradients[j][k].coord_map["dc_da"] = val_dc_da; 

			// set the activation with respect to the raw input 
			NN_gradients[j][k].coord_map["da_dz"] = val_da_dz;

			// partial of z with respect to this neurons bias
			NN_gradients[j][k].coord_map["dz_db"] = val_dz_db;



			}// end current training coord loop

		
		} // end layer looping for current training example	






	} // end i loop / all training examples complete



	


}



// load from folder constructor
NN::NN(std::string folder){

	// locate folder named FOLDER and open it
	// -> load values from NN_biases.txt to this->NN_biases
	// -> load values from NN_weights.txt to this->NN_weights
	// -> load metadata from metadata.txt to this objects metadata whatever ...


}






// function to save all weights biases and metadata to a folder
void NN::save_to_folder(std::string folder){


	// create a new folder or locate the existing folder with name FOLDER
	//	-> create or open a file called metadata.txt
	//		- should have metadata like equation trained on, num training examples, num forward etc.
	//		- write or overwrite current metadata
	//	-> either create or open NN_weights.txt and NN_biases.txt and overwrite or write the current 
	//	weight and bias values to those text files
	//		- write or overwrite current NN_biases and current NN_weights
}
