#include "NN.hpp"
#include <cmath>
#include <filesystem>
#include <fstream>



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




double NN::run_forward_prop(coord my_coord){
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

	return NN_activations[qty_hidden_layer + 1][0];
}


void NN::run_training_on_data(data my_data){
	// make the infrastructure to hold gradient and derivative values
	std::vector<std::vector<gradient_coord>> NN_gradients(this->qty_hidden_layer + 1);


////////////////// TRAINING FOR EACH COORDINATE /////////////////////////
	
	// for each training coord
	for  ( int i = 0 ; i < my_data.num_data_points ; i++){
	
	coord my_coord = my_data.test_data[i];
	// run the forward prop
	double network_guess = NN::run_forward_prop(my_coord);


		// for each layer in the network that has weights and biases
		for (int j = this->qty_hidden_layer ; j >= 0 ; j--){
			
			if ( j == this->qty_hidden_layer){

			// for each neuron in the current layer
			for (int k = 0 ; k < this->NN_activations[i + 1].size() ; k++){
			
			// set the cost with respect the activation 
			NN_gradients[i][j].coord_map["dc_da"] = std::abs(network_guess - static_cast<double>(my_coord.valid));

			// set the activation with respect to the raw input 
			
				if (NN_activations[i+1][j] == 0){
				NN_gradients[i][j].coord_map["da_dz"] = 0;
				} else{
				NN_gradients[i][j].coord_map["da_dz"] = 1;
				}

			// partial of z with respect to this neurons bias
			NN_gradients[i][j].coord_map["dz_db"] = 1; 


			// do this for all weights that are associated with this neuron
				for (int f = 0 ; f < this->NN_activations[i] ; f++){

				NN_gradients[i][j].coord_vector[f] = NN_activations[i][f]; 

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



			
			// do this for all weights that are associated with this neuron
				for (int f = 0 ; f < this->NN_activations[i] ; f++){

				NN_gradients[i][j].coord_vector[f] = NN_activations[i][f]; 

				}


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

// look for the folder first 
	try{
		if(std::filesystem::exists(folder)){
			if (std::filesystem::is_directory(folder)){
				std::cout << "folder " << folder << "  exists"  std::endl;
				return true;
			}
	
	} catch (const std::filesystem_error& e){
		std::cerr << "Filesystem error: " << e.what() << std::endl;
		return false;
	} // end try-catch

// look inside that folder to make sure that everything exists

std::filesystem::path folder(folder);

std::filesystem::path biases = folder / "biases.txt";

std::filesystem::path weights = folder / "weights.txt";

std::filesystem::path metadata = folder / "metadata.txt";

bool bias = false;
bool weights = false;
bool metadata = false;


// check to see if the files exist in the folder 
if(std::filesystem::exists(biases)){
	bias = true;
	std::cout << "bias file exists" << std::endl;
}
if(std::filesystem::exists(weights)){
	weights = true;
	std::cout << "weights file exists" << std::endl;
	
	} 

if(std::filesystem::exists(metadata)){
	metadata = true;
	std::cout << "metadata file exists" << std::endl;

}



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


// look for the folder first and create it if it doesn't exist 
	try{
		if(std::filesystem::exists(folder)){
			if (std::filesystem::is_directory(folder)){
				std::cout << "writing to folder: " << folder << std::endl;
				return true;


			} else {
	
			std::cerr << "folder given exists but is not a directory" << std::endl;
			return false;
			

			}
		} else {
			if (std::filesystem::create_directory(folder)){
			std::cout << "Folder created proceding to write to it" << std::endl;
			} else { std::cerr << "failed to create folder" << std::end;
			return false;
			}
		}
	

	} catch (const std::filesystem_error& e){
		std::cerr << "Filesystem error: " << e.what() << std::endl;
		return false;
	} // end try-catch

// look inside that folder to make sure that everything exists

std::filesystem::path folder(folder);

std::filesystem::path biases = folder / "biases.txt";

std::filesystem::path weights = folder / "weights.txt";

std::filesystem::path metadata = folder / "metadata.txt";

bool bias = false;
bool weights = false;
bool metadata = false;

if(std::filesystem::exists(biases)){
	bias = true;
	std::cout << "bias file exists" << std::endl;
} else {
	std::ofstream file(biases);	
	std::cout << "biases file created" << std::endl;
}
if(std::filesystem::exists(weights)){
	weights = true;
	std::cout << "weights file exists" << std::endl;
	
	} else {
	std::ofstream file(weights);
	std::cout << "created weights file" << std::endl;
	}

if(std::filesystem::exists(metadata)){
	metadata = true;
	std::cout << "metadata file exists" << std::endl;
}  else {
	std::ofstream file(metadata);
	std::cout << "created metadata file" << std::endl;
}

//////////////////////////////// check again ///////////////

if(std::filesystem::exists(biases)){
	bias = true;
	std::cout << "bias file exists" << std::endl;
}
if(std::filesystem::exists(weights)){
	weights = true;
	std::cout << "weights file exists" << std::endl;
	
	} 

if(std::filesystem::exists(metadata)){
	metadata = true;
	std::cout << "metadata file exists" << std::endl;
} 

// if they all exist then try to write to them
if(bias && weights && metadata){
	std::cout << "attempting to write to bias weights and metadata files " << std::endl;



} // end attempting to write to weights bias and metadata file 


} // end function 

