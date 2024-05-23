#ifndef NN_TRAINING_HPP
#define NN_TRAINING_HPP
#include <vector>
#include <iostream>
#include <memory>
#include "NN_init.hpp"
#include "NN_create_training_data.hpp"

struct neuron_partials{
  std::vector<double> dzi_dwi;
  double dzi_dbi = 0;
  double dai_dzi = 0;
  double dl_dai = 0;


};

struct NN_gradient_and_partials{
  NN_gradient_and_partials(NN& nn);
  



};


class NN_TRAINING{
  
  // initialize all my pointers as nullptr
  std::unique_ptr<NN> network_to_train_ptr = nullptr;
  training_data* training_data_ptr = nullptr;
  NN_gradient_and_partials* gradient_and_partials_ptr = nullptr;

  


  public:
  NN_TRAINING(NN* network_to_train_ptr,
               training_data* training_data_ptr,
               );

  ~NN_TRAINING();
  
  void run_all_training();
};

#endif
