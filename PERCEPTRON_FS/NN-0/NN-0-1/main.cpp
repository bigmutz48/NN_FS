#include <iostream>
#include <vector>
// need to include initialize.cpp header file 
#include <NN_initialize.h>




int main () {
  // declare the variables that will store the amounts of neurons that each layer will contain!!!
  int Input = 1000;
  int First = 12;
  int Second = 12;
  int Output = 10;

  // create instance of NN_initialize class 

  NN_initialize NN;
  


  // create each layer using Ptrs!!!!
  std::vector<double>* InputLayerPtr = NN.create_InputLayer(Input);
  std::vector<double>* FirstLayerPtr = NN.create_FirstLayer(First);
  std::vector<double>* SecondLayerPtr = NN.create_SecondLayer(Second);
  std::vector<double>* OutputLayerPtr = NN.create_OutputLayer(Output);
  
  // create the weights for each layer!!!!
  
  // input -> first layer
  std::vector<std::vector<double>>* WeightsFirstLayerMatrixPtr = NN.create_WeightsOneLayerMatrix(Input, First);

  // first layer -> second layer
  std::vector<std::vector<double>>* WeightsSecondLayerMatrixPtr = NN.create_WeightsOneLayerMatrix(First, Second);

  // second layer -> output 
  std::vector<std::vector<double>>* WeightsOutputLayerMatrixPtr = NN.create_WeightsOneLayerMatrix(Second, Output);


  // randomize all weight matrices
  
  //has to be done for each matrix
  NN.set_MatrixOneLayer_ToRandom(WeightsFirstLayerMatrixPtr);
  NN.set_MatrixOneLayer_ToRandom(WeightsSecondLayerMatrixPtr);
  NN.set_MatrixOneLayer_ToRandom(WeightsOutputLayerMatrixPtr);


  return 0;
}
