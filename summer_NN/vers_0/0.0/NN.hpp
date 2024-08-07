/*
 *  Purpose of this class is to represent a neural net object.
 *
 *   -> hard coded with one output
 *
 *
 *
 *
 *
 *
 *
 * */



#ifndef NN_CPP
#define NN_CPP
#include <vector>
#include <iostream>
#include <memory>
#include "data.hpp"
#include "coord.hpp"
#include "gradient_coord.hpp"
#include "math.hpp"
/*
 *
 *	NEURAL NET OBJECT (NN):
 *	this object should contain a neural net that can be easily constructed with the non-default constructor.
 *
 *	METHODS:
 *	- constructor
 *	- deconstructor
 *	- run_forward_prop 
 *		-> does forward prop for a given coordinate
 *		-> return a boolean with whether or not that coord is valid according to the network
 *
 *
 *
 * */


class NN{
///////////////////////// NETWORK METADATA ////////////////////////////////

// generic metadata
	int num_forward_pass = 0;
	int backprop_pass = 0;


// network training metadata 
	std::string equation;
	int num_training_examples = 0;
	



// network structure parameters
int qty_hidden_layer_density;
int qty_hidden_layer;
int qty_inputs;
//int qty_outputs;
// -> will have one output


//////////////////////////  NETWORK STRUCTURE ////////////////////////////////




// actiavtions
std::vector<std::vector<double>> NN_activations;


// weights

std::vector<std::vector<std::vector<double>>> NN_weights;


// biases

std::vector<std::vector<double>> NN_biases;




///////////////////////////////// PUBLIC METHODS ////////////////////////////////////////
	public:

	
	// constructor
	NN(int qty_inputs, int qty_hidden_layer_density, int qty_hidden_layer);
	~NN();

	
	// load from folder constructor
	NN(std::string folder);

	//takes in one coord and does a forward prop on it and returns
	//whether or not the coordinate is a valid solution to EQUATION
	double run_forward_prop(coord my_coord);

	// how to run training on a data set
	void run_training_on_data(data my_data);	
	
	// function to save all weights biases and metadata to a folder
	void save_to_folder(std::string folder);
};







#endif
