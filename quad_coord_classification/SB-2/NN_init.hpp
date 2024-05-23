#ifndef NN_INIT_HPP
#define NN_INIT_HPP
#include <vector>
#include <iostream>

// This class is only for initializng a blank neural net with no parameters

struct neuron{
  int layer_index;
  double activation_val;
  double bias_val;
  double raw_activation_val;
  std::vector<double>* weights_vector = nullptr;
  
};


struct NN{
  //init parameters
  int input =  -1;
  int first =  -1;
  int second = -1;
  int third =  -1;
  int output = -1;


  // constructor for object
  NN(int input, int first, int second, int third, int output);
  // main network info
  int num_training_examples;
  std::vector<double>* input_layer = nullptr;
  std::vector<neuron>* first_hidden_layer_neurons = nullptr;
  std::vector<neuron>* second_hiddenlayer_neurons = nullptr;
  std::vector<neuron>* third_hidden_layer_neurons = nullptr;
  std::vector<neuron>* output_layer_neurons = nullptr

  // gradient and backprop info

  // initialize the weights and biases with random values ***

};



#endif
