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

void Training::run_BackPropOneTrainingExample(int index_CurrentTrainingExample){
  


}

void Training::run_AllTraining(){
  for (int i = 0 ;  i < TrainingDataPtr->size() ; i++){
    run_BackPropOneTrainingExample(i);
  }

}


void Training::run_BackPropOneLayer(int index_CurrentTrainingExample, int index_NNLayer){
  // this is where basically all the magic should happen and all the actual writing should happen
  

  // need to collect and store the 

}
