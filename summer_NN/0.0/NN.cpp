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






