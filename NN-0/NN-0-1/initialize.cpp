#include <iostream>
#include <vector>

class NN_initialize {
  public:
    
    //these functions should allow the user to easily initialize 4 empty vectors where neuron activations can be stored

    std::vector<double>* create_InputLayer (int qty) {
      std::vector<double>* InputLayerPtr = new std::vector<double>(qty);
      return InputLayerPtr;
    }

    std::vector<double>* create_FirstLayer (int qty) {
      std::vector<double>* FirstLayerPtr = new std::vector<double>(qty);
      return FirstLayerPtr;
    }

    std::vector<double>* create_SecondLayer (int qty) {
      std::vector<double>* SecondLayerPtr = new std::vector<double>(qty);
      return SecondLayerPtr;
    }

    std::vector<double>* create_OutputLayer (int qty) {
      std::vector<double>* OutputLayerPtr = new std::vector<double>(qty);
      return OutputLayerPtr;
    }



    // these functions are supposed to help the user create the weights for each neuron and link them up
    std::vector<double>* create_WeightsToOneNeuron (int recieving) {
      std::vector<double>* WeightsToOneNeuronPtr = new std::vector<double>(recieving);
      return WeightsToOneNeuronPtr;
    // I would really like to store all the variables for each neuron in one vector or maybe in one matrix or an array of vectors
    //  -> it would be really nice if I i could somehow link each neuron to the weights and one bias that belongs to it ... this might prove nearly impossible though and could slow down the program speed
    }
    

    // call all functions to initialize the empty neural network
    void ..... // this might not actually work ... unless I return an array?


    // could also make a function to create a matrix of weights for one layer ??
    

    std::vector<std::vector<double>>* create_WeightsOneLayerMatrix (int incoming_layer, int current_layer) { // the return type is a pointer to a matrix (a vector full of vector<double>)
      std::vector<std::vector<double>>* WeightsOneLayerMatrixPtr = new std::vector<std::vector<double>>(current_layer , std::vector<double>(incoming_layer));
      return WeightsOneLayerMatrixPtr;
    }

}








int main () {

  return 0;
}
