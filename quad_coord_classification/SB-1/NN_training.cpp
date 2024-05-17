#include <iostream>
#include <vector>
#include "NN_basics.hpp"
#include "NN_training.hpp"
#include "NN_data_gen.hpp"

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




void Training:run_BackpropOneTrainingExample(){
  //for each layer which has weights and biases to take gradients of
  for (int i = 5 ; i > 1 ; i--){
    
    //for each neuron in the layer that we are looking after
    for(int j = 0 ; j < this->NeuronsPtr[i] ; j++){
      // values to be shared 
      double dLt_dA = 0;
      double dA_dZ = 0;
      
      // when we are looking at the output layer
      if(i == 5){
        // calculate dLt_dA
        for(int h = 0 ; h < this->NeuronsPtr[i].size() ; h++){
          dLt_dA += this->NeuronsPtr[i][h] - this->TrainingDataPtr[TrainingIndexCtr].y;
        
        if(ZValuesPtr[i - 1][j] > 0){
          dA_dZ = 1;
        }
        
        }
      }

      // when we are looking at the remaining 3 layers of weights and biases
      else{


      }

      


      // value for bias always 1
      dz_dBi = 1;

      // write the value
      GradientBiasesPtr[i - 1][j] = dLt_dA * dA_dZ * dZ_dBi; 

      // for each weight that belongs to neuron j in layer i
      for(int k = 0 ; k < this->NeuronsPtr[i - 1] ; k++){
      // weight specific
      double dZ_dWjk = 0;
      
      // when we are looking at the output layer
      if(i == 5){
        dZ_dWjk = this->NeuronsPtr[i - 1][k]
      } 


      // when we are looking at the remaining 3 layers of weights and biases
      else {

      }


      // write the value
      GradientWeightsPtr[i - 1][j][k] = 
      }
    }
  }
}



// function to run all the training for a specified amount of training examples
void Training::run_AllTraining(){
  // run training for the amount of training examples that there are
  for (int i = 0 ; i < this->TrainingDataPtr->size() ; i++){
      run_BackpropOneTrainingExample();
  }

}
