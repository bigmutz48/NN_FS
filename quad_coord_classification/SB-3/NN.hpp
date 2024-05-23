#ifndef NN_HPP
#define NN_HPP
#include <vector>
#include <optional>
#include <memory>



/****************************************************************************************************
 This file is soley responsible for initializing a functional neural net either from a file or with random 
 weights and biases

 This includes:
    initializing all weights and biases
    providing all the methods that the net needs to function
 
 
 **************************************************************************************************/


struct neuron{
    // weights and biases
  std::vector<double> weights;
  double bias;

    // activations
  double z;
  double a;
};





class NN {

  
    // metadata
      int qty_input;
      int qty_first;
      int qty_second;
      int qty_third;
      int qty_output;
      bool load_from_file = false;
      int num_training_examples;
      std::string weights_file_name;
      std::string biases_file_name;
      std::string metadata_file_name;

      // actual network
        std::vector<double> input_layer(qty_input);
        std::vector<neuron> first_layer(qty_first);
        std::vector<neuron> second_layer(qty_second);
        std::vector<neuron> third_layer(qty_third);
        std::vector<neuron> output_layer(qty_output);


      ////////////////////////// NETWORK METHODS ///////////////////////////////
      

      ///////// set up 
      void populate_weights_from_file();
      void populate_biases_from_file();
      void populate_metadata_from_file();

      void populate_biases();
      void populate_weights();


      //////// forward prop methods 

      
      ////////////////////////// END NETWORK METHODS ///////////////////////////////



      //////////////////////// NETWORK SET UP //////////////////////////////////////
      if (load_from_file){
        populate_weights_from_file();
        populate_biases_from_file();
        populate_metadata_from_file();
      } 
      // if we are not loading from a file then we want to set this network up randomly
      else{
        populate_weights();
        populate_biases();
      }

      //////////////////////// END NETWORK SET UP //////////////////////////////////////
 

  public:
    NN(int input, int first, int second, int third, int output,
       bool load_from_file, std::string weights_file_name, std::string biases_file_name, std::string metadata_file_name);
    ~NN();

    // return the output of the network
    double run_forward_prop(int x, int y);
};


#endif
