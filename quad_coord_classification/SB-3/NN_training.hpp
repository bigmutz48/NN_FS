#ifndef NN_training_hpp
#define NN_training_hpp
#include "NN.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include "my_math.hpp"

/**********************************************************************************************************************

PURPOSE: run training on an already existing network using already existing training data 



**********************************************************************************************************************/


struct neuron_partials{

  // main partials 
      
      // partial between this neurons a and this neurons z
      double dai_dzi;
      // partial between cost and this a 
      double dc_dai;
      


      // vector of weights partials
      std::vector<double> dzi_dwi_vec;

      // partial between this z and this b always equals 1 
      double dzi_dbi = 1;

      // partial beteen this z (layer n) and the a from the previous layer (layer n - 1)
      std::vector<double> dzi_daj_nminus1_vec;


};



class NN_training{
  NN NN_to_train;
  training_data my_training_data;

  ////////////////////////////////// METADATA ///////////////////////////////////////////////////////////////
  

  int training_example_ctr = 1;
  double cost;
  
  ////////////////////////////////// END METADATA ///////////////////////////////////////////////////////////////
  


  ////////////////////////////////// PARTIALS STORAGE ///////////////////////////////////////////////////////////////
  std::vector<neuron_partials> partials_first_layer(NN_to_train.get_first_layer.size());
  std::vector<neuron_partials> partials_second_layer(NN_to_train.get_second_layer.size());
  std::vector<neuron_partials> partials_third_layer(NN_to_train.get_third_layer.size());
  std::vector<neuron_partials> partials_output_layer(NN_to_train.get_output_layer.size());
  ////////////////////////////////// END PARTIALS STORAGE ///////////////////////////////////////////////////////////////



  //////////////////////// METHODS FOR NN TRAINING ////////////////////////////////////////////////

  // this function needs to calculate and write the partials for every layer for the current training example 
  void calculate_partials_for_current_training_example();


  //////////////////////// END METHODS FOR NN TRAINING ////////////////////////////////////////////////





  public:
    NN_training(NN& network_to_train, training_data& my_training_data);
    ~NN_training();
  void run_training_next_example();
  void run_all_training();
};

#endif
