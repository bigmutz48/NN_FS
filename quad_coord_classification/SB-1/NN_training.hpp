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
             std::vector<coord>* TrainingDataPtr,
             double learning_rate
             );

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
    double learning_rate; 
   

   // create the location to store the gradient of the network
      // create the function to generate it properly
      std::vector<std::vector<std::vector<double>>> create_GradientWeights();
    
      // function to create biases gradient 
      std::vector<std::vector<double>> create_GradientBiases();
      

      // actual vectors to access
      auto GradientWeights = create_GradientWeights();

      auto GradientBiases = create_GradientBiases();


   // partial derivative functions here
        double dL_da(int index_a, std::vector)
        
        double da_dz();

        double dz_dw();

        double dz_db();

   // functions to actually run training
        // Function takes only the index of the layer it is currently operating on
        // go through each neuron and populate the gradients of the weights and biases appropriately
        void run_TrainingOneLayer(int index);

        // FUNCTION: run run_TrainingOneLayer 4 times 
        void run_TrainingEachLayer();



};






#endif
