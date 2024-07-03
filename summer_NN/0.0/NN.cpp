#include "NN.hpp"

	
NN(int qty_inputs, int qty_outputs, int qty_hidden_layer_density, int qty_hidden_layer);
	: this->qty_inputs(qty_inputs), this->qty_outputs(qty_outputs), this->qty_hidden_layer(qty_hidden_layer),
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
NN_activations[qty_hidden_layer + 2] = std::vector<double>(qty_outputs);


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
} else if( i == qty_hidden_layer + 2){
	NN_weights[i] = std::vector<std::vector<double>>(qty_outputs, qty_hidden_layer_density, 1);
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
	for (int i = 0 ; i < this->qty_outputs ; i++){
	
		// set the last element of NN_activations equal to the second to last NN_activations dotted with the last NN_weights
	NN_activations[this->qty_hidden_layer + 1][i] 
	= math.ReLU(math.dot_product(NN_activations[qty_hidden_layer], NN_weights[qty_hidden_layer]) + NN_biases[qty_hidden_layer]);
	}

}


void NN::run_training_on_data(DATA my_data){
	// make the infrastructure to hold gradient and derivative values
	std::vector<std::vector<double>> NN_gradients(this->qty_hidden_layer + 1, 0.0);


////////////////// TRAINING FOR EACH COORDINATE /////////////////////////
	for  ( int i = 0 ; i < my_data.num_data_points ; i++){
	
	
	










	} 


	// run the forward prop
	NN::run_forward_prop(my_coord);
	


}

//takes in one coord and does a forward prop on it and returns
	//whether or not the coordinate is a valid solution to EQUATION
	bool run_forward_prop(coord my_coord);


	void run_training_one_example(coord my_coord);
