#ifndef NN_INITIALIZE_H
#define NN_INITIALIZE_H

#include <vector>

class NN_initialize {
  public:
    
    // functions to create each neural layer 
    std::vector<double>* create_InputLayer(int qty);
    std::vector<double>* create_FirstLayer(int qty);
    std::vector<double>* create_SecondLayer(int qty);
    std::vector<double>* create_OutputLayer(int qty);
   

    // create the weight matrices for each layer and initialize all weights to be random doubles between -1 and 1
    std::vector<std::vector<double>>* create_WeightsOneLayerMatrix(int incoming_layers, int current_layers);
    void set_MatrixOneLayer_ToRandom(std::vector<std::vector<double>>* MatrixPtr);

    // create and initialize each bias to be the same number which will be decided through this callable function
    std::vector<double>* create_BiasesOneLayer (int current_layer, double init_bias);

};

#endif
