#ifndef NN_TRAINING_HPP
#define 
#include <vector>
#include <iostream>
#include "NN_data_gen.hpp"



class Training{
  public:
    // constructors and destructors

    Training(std::vector<std::vector<std::vector<double>>>* WeightsPtr,
             std::vector<std::vector<double>>* NeuronsPtr,
             std::vector<std::vector<double>>* BiasesPtr,
             std::vector<coord>* TrainingDataPtr;

    ~Training();

      
    void run_AllTraining();

    
  private:
    double CostFunction(double )
    void run_BackPropOneLayer(int index_CurrentTrainingExample, int index_NNLayer)

    // this function should get called for each training example and bias update
    void run_BackPropOneTrainingExample(int index_CurrentTrainingExample);

    // Parameters to be set by the constructor when it is called     
    std::vector<std::vector<std::vector<double>>>* WeightsPtr;
    std::vector<std::vector<double>>* NeuronsPtr;
    std::vector<std::vector<double>>* BiasesPtr;
    std::vector<coord>* TrainingDataPtr;
   
    // partials functions 



};






#endif
