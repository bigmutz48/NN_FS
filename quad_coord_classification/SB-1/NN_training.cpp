#include <iostream>
#include <vector>
#include "NN_basics.hpp"
#include "NN_training.hpp"
#include "NN_data_gen"

Training::Training(std::vector<std::vector<std::vector<double>>>* WeightsPtr,
                   std::vector<std::vector<double>>* NeuronsPtr,
                   std::vector<std::vector<double>>* BiasesPtr,
                   std::vector<coord>* TrainingDataPtr,
                   double LearningRate){
this-> WeightsPtr = WeightsPtr;
this-> NeuronsPtr = NeuronsPtr;
this-> BiasesPtr = BiasesPtr;
this-> TrainingDataPtr = TrainingDataPtr;
this-> LearningRate = LearningRate;
}

Training::Training(){
  std::cerr <<"You are trying to use the default constructor for Training which is not allowed" << std::endl;
}


void Training::run_TrainingOneLayer(int layer_index){
// imagine that you are at the first layer 
  

  // for each neuron in the current layer 
  for (int i = 0 ; i < NeuronsPtr[layer_index].size() ; i++){
    // for each weight for this specific neuron
    for (int j = 0 ; j < NeuronsPtr[layer_index - 1].size() ; j++){
      
      //create a temporary variable to store the value of the gradient of the cost function with respect to this weight
      double weightgradient = 0;



      //3 things to calculate!
      //1) dL_dA -> the derivative of the loss with respect to the activation
      //2) dA_dZ -> the derivative of the activation with respect to the raw input
      //3) dZ_dW_ij -> the derivative of the raw input with respect to the specific weight we are looking at

      // set these values up so we can fill them up
      double dL_dA = 0;
      double dA_dZ = 0;
      double dZ_dW_ij = 0;




      // going to run the calculations here

            // first ... very easy ... dZ_dW_ij is equal to A^(n-1)_j

            



    // calculate the gradient for this weight
    weightgradient = dL_dA * dA_dZ * dZ_dW_ij;

    // actually do the assignment here
        // layer_index - 1 because GradientWeights has only four indexes whereas NeuronsPtr has 5
        // and then for the ith neuron inside of there
        // and finally for the jth weight
        this-> GradientWeights[layer_index - 1][i][j] = weightgradient;
    }
  }


}
