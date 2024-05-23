#ifndef NN_training_hpp
#define NN_training_hpp
#include "NN.hpp"
#include <vector>
#include <memory>
#include <iostream>


/**********************************************************************************************************************

PURPOSE: run training on an already existing network using already existing training data 



**********************************************************************************************************************/

struct NN_partials{
  NN_partials();
  ~NN_partials();
};


class NN_training{
  std::unique_ptr<NN> network_to_train = nullptr;
  std::unique_ptr<training_data> my_training_data = nullptr;

  public:
    NN_training(NN& network_to_train, training_data& my_training_data);
    ~NN_training();
};

#endif
