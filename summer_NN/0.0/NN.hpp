/*
 *  Purpose of this class is to represent a neural net object.
 *
 *
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


/*
 *	COORD OBJECT:
 *this coordinate object has an x and y pair, and then a boolean that declares
 * whether or not this coord object is a valid solution to the equation.
 *
 *
 *
 *
 *
 *
 * */

struct coord{
	double x = 0 ;
	double y = 0 ;
	bool valid = false;
};





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
// network parameters
int qty_hidden_layer_density;
int qty_hidden_layer;
int qty_inputs;
int qty_outputs;

// actiavtions
std::vector<std::vector<double>> NN_activations;


// weights

std::vector<std::vector<std::vector<double>>> NN_weights;


// biases

std::vector<std::vector<double>> NN_biases;





	public:
// methods to operate on the network itself
	
	// constructor
	NN(int qty_inputs, int qty_outputs, int qty_hidden_layer_density, int qty_hidden_layer);
	~NN();


	//takes in one coord and does a forward prop on it
	bool run_forward_prop(coord my_coord);

	


};







#endif
