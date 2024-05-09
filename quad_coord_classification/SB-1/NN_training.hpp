#ifndef NN_TRAINING_HPP
#define NN_TRAINING_HPP 
#include <vector>
#include <iostream>
#include "NN_data_gen.hpp"



class Training{
  public:
    // constructors and destructors

    Training(std::vector<std::vector<std::vector<double>>>* WeightsPtr,
             std::vector<std::vector<double>>* NeuronsPtr,
             std::vector<std::vector<double>>* BiasesPtr,
             std::vector<coord>* TrainingDataPtr,
             std::vector<std::vector<double>>* ZValuesPtr,
             double learning_rate
             );

     Training();

    ~Training();

      
    void run_AllTraining();

    
  private:

//////////////// PARAMETERS ///////////////////////////////////////////////////////////////////////////////////

    // Parameters to be set by the constructor when it is called     
    std::vector<std::vector<std::vector<double>>>* WeightsPtr = nullptr;
    std::vector<std::vector<double>>* NeuronsPtr = nullptr;
    std::vector<std::vector<double>>* BiasesPtr = nullptr;
    std::vector<coord>* TrainingDataPtr = nullptr;
    std::vector<std::vector<double>>* ZValuesPtr = nullptr;
    double LearningRate;

    // other shared parameters
    int TrainingIndexCtr = 0;   


////// END PARAMETERS /////////////////////////////////////////////////////////////////////////////////////////

//////////////////// FUNCTIONS ////////////////////////////////////////////////////////////////////////////////


   // create the location to store the gradient of the network
      // create the function to generate it properly
      std::vector<std::vector<std::vector<double>>> create_GradientWeights();
    
      // function to create biases gradient 
      std::vector<std::vector<double>> create_GradientBiases();
      

      // actual vectors to access
      std::vector<std::vector<std::vector<double>>> GradientWeights = create_GradientWeights();

      std::vector<std::vector<double>> GradientBiases = create_GradientBiases();


   // functions to actually run training
        // Function takes only the index of the layer it is currently operating on
        // go through each neuron and populate the gradients of the weights and biases appropriately
        void run_TrainingOneLayer(int layer_index);

    //FUNCTION:run training one layer 4 times for a given training example
    //
    //-> the index of the current training example is kept in a parameter that belongs to this object
    void run_BackPropOneTrainingExample();

//////////////////// END FUNCTIONS ////////////////////////////////////////////////////////////////////////////////
};






#endif
