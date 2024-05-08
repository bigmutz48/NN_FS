#include <iostream>
#include <vector>
#include "NN_basics.hpp"
#include "NN_training.hpp"
#include "NN_data_gen"

Training::Training(std::vector<std::vector<std::vector<double>>>* WeightsPtr,
                   std::vector<std::vector<double>>* NeuronsPtr,
                   std::vector<std::vector<double>>* BiasesPtr,
                   std::vector<coord>* TrainingDataPtr,
                   std::vector<std::vector<double>>* ZValuesPtr,
                   double LearningRate){
this-> WeightsPtr = WeightsPtr;
this-> NeuronsPtr = NeuronsPtr;
this-> BiasesPtr = BiasesPtr;
this-> TrainingDataPtr = TrainingDataPtr;
this-> LearningRate = LearningRate;
this-> ZValuesPtr = ZValuesPtr;
}

Training::Training(){
  std::cerr <<"You are trying to use the default constructor for Training which is not allowed" << std::endl;
}


void Training::run_TrainingOneLayer(int layer_index){
// imagine that you are at the first layer 
  //

  // for each neuron in the current layer 
  for (int i = 0 ; i < NeuronsPtr[layer_index].size() ; i++){




//////////////////////////////////// GENERAL SETUP FOR A NEURON  //////////////////////////////////////////


      // set dL_dA here so you don't continously loop through in calculating 
      // every single weight ... that would be a waste of time
      double dL_dA = 0;
      double dA_dZ = 0;

      //3 things to calculate!
      //1) dL_dA -> the derivative of the loss with respect to the activation
      //2) dA_dZ -> the derivative of the activation with respect to the raw input
      //3) dZ_dW_ij -> the derivative of the raw input with respect to the specific weight we are looking at



            // DERIVATIVE: dA_dZ 
            // this is a lot harder ... going to need to have the z value for the current layer_index at neuron j
            if (ZValuesPtr[layer_index - 1][i] <= 0){
              dA_dZ = 0; 
            } else {
              dA_dZ = 1;
            } 

            //DERIVATIVE: dL_dA
            // this one is only moderately loco
            // this one is the hardest and requires a sum function
            for (int i = 0 ; i < NeuronsPtr[layer_index].size() ; i++){
              dL_dA += (NeuronsPtr[layer_index][i] - )
            }
    
    
//really quickly we want to calculate the gradient for the bias of this neuron 
//////////////////////////////////// BIASES ///////////////////////////////////////////

double biasgradient = 0;


//DERIVATIVE: dZ_dBi
//this describes the relationship between the bias and the raw input function
dZ_dBi = 1



biasgradient = dL_dA * dA_dZ * dZ_dBi; 

    this->BiasesPtr[layer_index - 1][i] = biasgradient;









      // We want to:
      // 1) calculate dZ_dW_ij for the weight ij 
      // 2) multiply dZ_dW_ij dL_dA and dA_dZ 
      // 3) write that product to the gradient jagged array
      // for each weight for this specific neuron
      for (int j = 0 ; j < NeuronsPtr[layer_index - 1].size() ; j++){
      // initialize these values equal to zero ... they will only be used in this j for loop       
      double weightgradient = 0;
      double dZ_dW_ij = 0;

      // calculate the gradient for this weight
    weightgradient = dL_dA * dA_dZ * dZ_dW_ij;
    
    // actually do the assignment here
        // layer_index - 1 because GradientWeights has only four indexes whereas NeuronsPtr has 5
        // and then for the ith neuron inside of there
        // and finally for the jth weight
        this-> GradientWeights[layer_index - 1][i][j] = weightgradient;
    }// move to next neuron
  
// calculate the gradient for the bias of this neuron and write that


  }


}
