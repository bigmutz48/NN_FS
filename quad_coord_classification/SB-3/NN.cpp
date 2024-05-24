#include "NN.hpp"
#include <iostream>
#include <vector>
#include "my_math.hpp"


    // throw an error if this gets called     
NN::NN(){
  std::cout << "You are trying to create an NN with the default constructor which is not allowed" << std::endl;
}

    // non default constructor this is what should be used
NN::NN(int input, int first, int second, int third, int output,
       bool load_from_file, std::string weights_file_name, std::string biases_file_name, std::string metadata_file_name){
  
      this-> qty_input = input;
      this-> qty_first = first;
      this-> qty_second = second;
      this-> qty_third = third;
      this-> qty_output = output;
      this-> load_from_file = load_from_file;
      this-> weights_file_name = weights_file_name;
      this-> biases_file_name = biases_file_name;
      this-> metadata_file_name = metadata_file_name;

      // don't know what to do with this guy yet
      int num_training_examples;
}
~NN();
