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

struct NN_partials{
  // metadata
  int qty_input;
  int qty_first;
  int qty_second;
  int qty_third;
  int qty_output;

  std::vector<neuron_partials> input(qty_input);
  std::vector<neuron_partials> first(qty_first);
  std::vector<neuron_partials> second(qty_second);
  std::vector<neuron_partials> third(qty_third);
  std::vector<neuron_partials> output(qty_output);
  NN_partials(NN& nn);
  ~NN_partials();
  



};



class NN_TRAINING{
  
  // initialize all my pointers as nullptr
  std::unique_ptr<NN_RUN> network_to_train_ptr = nullptr;
  std::unique_ptr<training_data> training_data_ptr = nullptr;
  std::unique_ptr<NN_partials> NN_partials_ptr = nullptr;

  // create the object for the partials 
  NN_partials_ptr = std::make_unique<NN_partials>(*network_to_train_ptr);


  // training functions
  
  // training parameters
  int current_layer;
  int current_neuron;
  int current_training_example;

  void run_training_one_example();
    void run_forward_prop;
    void calculate_partials_next_neuron();
    void update();
    
  

  public:
  // user only needs to have access to a few functions
  NN_TRAINING(NN& network_to_train_ptr,
               training_data& training_data_ptr,
               );

  ~NN_TRAINING();
  
  void run_all_training();
};

#endif
