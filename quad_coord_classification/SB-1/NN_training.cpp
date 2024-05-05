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
}

Training::Training(){
  std::cerr <<"You are trying to use the default constructor for Training which is not allowed" << std::endl;
}



void Training::run_AllTraining(){
for (int i = 0 ; i < this->TrainingDataPtr->size() ; i++ ){
  run_BackPropOneTrainingExample(i);
}
}

// this function is going to be absolutely massive ... and thats just going to have to be ok
void Training::run_BackPropOneTrainingExample(int index_CurrentTrainingExample){
  // for the current training example
  

    // going to need to write out the partial derivatives in here as lambda sudofunctions

    double dL_dW = []()


    // going to need to have a way to store each of the partial derivatives
    // I can just hard code them in right here
   




    for (int i = 0 ; i < 4 ; i++){
      // for 4 iterations each representing the set of weights and biases between two layers and their updates
    }

}

