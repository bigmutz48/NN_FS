#ifndef NN_basics
#define NN_basics
#include <vector>






/* INITIALIZE A 5 LAYER NEURAL NETWORK: basic program that creates a neural net with the following
 -> a randomized weight matrix for each layer exluding the input LAYER
 -> a randomized bias array for each layer
 -> properly sized JaggedArray to hold current neuron activations
 *
 *
 *
 *
 *
 *
 *
 * the point of this program is to just create a basic neural net 
 * I am really trying to speed up my dev process by making things that can be used
 * in every iteration of the program. It's very inefficient to be rewriting the entire program every time that I am making a new version of my project
 * I really want to only be rewriting specific parts of my program every time I make a new version, and am hoping to have a lot of functions
 * that I will never have to change and can be used in basically every iteration going forward*/ 







// class for user to interact with
class init_NN{
  

// user doesn't need to access very many parts of this class!!
  public:
    int qty_InputLayer;
    int qty_FirstLayer;
    int qty_SecondLayer;
    int qty_ThirdLayer;
    int qty_OutputLayer;


    std::vector<std::vector<std::vector<double>>> WeightsMain;
    std::vector<std::vector<double>> NeuronsMain;


}







#endif
