#ifndef NN_TRAINING_HPP
#define NN_TRAINING_HPP
#include <vector>
#include <iostream>
#include <memory>


struct neuron_double_partials{
  std::vector<double> dzi_dwi;

};

struct NN_gradient_and_partials{
  NN_gradient_and_partials(NN& nn);
  


};


class NN_TRAINING{
  

  std::unique_ptr<NN> network_to_train_ptr = nullptr;
  training_data* training_data_ptr = nullptr;
  NN_gradient_and_partials* SGD = nullptr;

  

  public:
  RUN_TRAINING(NN* network_to_train_ptr,
               training_data* training_data_ptr,
               );

  ~RUN_TRAINING();
  
  void run_all_training();
};

#endif
