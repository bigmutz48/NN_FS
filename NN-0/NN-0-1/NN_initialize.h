#ifndef NN_INITIALIZE_H
#define NN_INITIALIZE_H

#include <vector>

class NN_initialize {
  public:
    std::vector<double>* create_InputLayer(int qty);
    std::vector<double>* create_FirstLayer(int qty);
    std::vector<double>* create_SecondLayer(int qty);
    std::vector<double>* create_OutputLayer(int qty);
    std::vector<double>* create_WeightsToOneNeuron(int recieving);
    
    std::vector<std::vector<double>>* create_WeightsOneLayerMatrix(int incoming_layers, int current_layers);
    void set_MatrixOneLayer_ToRandom(std::vector<std::vector<double>>* MatrixPtr);
};

#endif
