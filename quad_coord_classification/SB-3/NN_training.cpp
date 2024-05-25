#include "NN_training.hpp"
#include "NN_create_training_data"



#include <iostream>
// default constructor should throw an error
NN_training::NN_training(){
  std::cout << "You are trying to use the default constructor for NN_training which is not allowed" << std::endl;
}

//nondefault constructor
NN_training::NN_training(NN& network_to_train, training_data& my_training_data):

  // member initializer list for this constructor
NN_to_train(network_to_train),
my_training_data(my_training_data){
  // not sure that this constructor needs to do anything passed this
}

~NN_training::NN_training(){}



// should take no parameters .... uses this->
void NN_training::calculate_partials_for_current_training_example(){
    // look at the output
    for (int i = 0 ; i < this->NN_to_train.get_output_layer().size() ; i++)[
      // each neuron

    ]
}


void NN_training::run_training_next_example(){

}

void NN_training::run_all_training(){
  do {
    NN_training::run_training_next_example();
  } while (this->training_example_ctr < my_training_data.get_num_training_examples());
}
