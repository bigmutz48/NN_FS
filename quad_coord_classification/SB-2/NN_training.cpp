#include <iostream>
#include "NN_training.hpp"
#include <memory>

NN_TRAINING::NN_TRAINING(NN* network_to_train_ptr,
               training_data* training_data_ptr,
               ){
this-> network_to_train_ptr = network_to_train_ptr;
this-> training_data_ptr = training_data_ptr;

gradient_and_partials mygradient;
this->gradient_and_partials_ptr = std::make_unique<mygradient>;
}
