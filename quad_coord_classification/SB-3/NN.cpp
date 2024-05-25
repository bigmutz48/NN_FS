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

// functions for initializing the weights and biases either from a file or randomly
// these functions take no arguments

void NN::populate_weights_from_file(){
  if (!(this->load_from_file)){
    std::cerr << "You are trying to populate weights from a file but load == false" << std::endl;
    return;
  } else if (this->load_from_file){
    std::cout << "loading weights from file" << std::endl;
    // main body should go here
    

    // attempt to open the file
    std::ifstream weights(this->weights_file_name);

    if(!weights.is_open){
        std::cerr << "failed to open the weights file" << std::endl;
        return;  
    } else{
      std::cout << "weights file is open " << std::endl;
                
        // populate the weights of the first layer
          for (int i = 0 ; i < this->qty_first ; i++){
            for (int j = 0 ; j < this->qty_input ; j++){
              // populate the weights one by one
              weights >> this->first_layer[i].weights[j];
            }
          }



        // populate the weights of the second layer  
          for (int i = 0 ; i < this->qty_second ; i++){
            for (int j = 0 ; j < this->qty_first ; j++){
              // populate the weights one by one
              weights >> this->second_layer[i].weights[j];
            }
          }
        

        // populate the weights of the third layer  
          for (int i = 0 ; i < this->qty_third ; i++){
            for (int j = 0 ; j < this->qty_second ; j++){
              // populate the weights one by one
              weights >> this->third_layer[i].weights[j];
            }
          }
        

        // populate the weights of the output layer  
          for (int i = 0 ; i < this->qty_output ; i++){
            for (int j = 0 ; j < this->qty_third ; j++){
              // populate the weights one by one
              weights >> this->output_layer[i].weights[j];
            }
          }





        std::cout << "finished populating weights from file :)" << std::endl;


      }
  

  }
}



void NN::populate_biases_from_file(){
  if (!(this->load_from_file)){
    std::cerr << "You are trying to populate biases from a file but load == false" << std::endl;
    return;
  } else if (this->load_from_file){
    std::cout << "loading biases from file" << std::endl;
    // main body should go here
  
      
    // attempt to open the file
    std::ifstream biases(this->biases_file_name);

    if(!biases.is_open){
        std::cerr << "failed to open the biases file" << std::endl;
        return;  
    } else{
      std::cout << "biases file is open " << std::endl;

      for (int i = 0 ; i < this->qty_first ; i++){
        biases >> this->first_layer[i].bias;
      }

      for (int i = 0 ; i < this->qty_second ; i++){
        biases >> this->second_layer[i].bias;
      }

      for (int i = 0 ; i < this->qty_third ; i++){
        biases >> this->third_layer[i].bias;
      }

      for (int i = 0 ; i < this->qty_first ; i++){
        biases >> this->output_layer[i].bias;
      }
      
        std::cout << "Finished populating biases from file !!" << std::endl;

        

  }
}


void NN::populate_metadata_from_file(){
  if (!(this->load_from_file)){
    std::cerr << "You are trying to populate metadata from a file but load == false" << std::endl;
    return;
  } else if (this->load_from_file){
    std::cout << "loading metadata from file" << std::endl;
    // main body should go here
      
        std::ifstream metadata(metadata_file_name);

        if(metadata.is_open){
          std::cout << "metadata file opened!" << std::endl;
        } else {
          std::cerr << "failed to open the metadata file!" << std::endl;
        }

        metadata >> this->qty_input;
        metadata >> this->qty_first;
        metadata >> this->qty_second;
        metadata >> this->qty_third;
        metadata >> this->qty_output;
        metadata >> this->num_examples_trained_on;
          




        // metadata
  }
}

void NN::populate_random_weights(){
  if(this->load_from_file){
    std::cerr << "You are trying to populate weights with random values but load_from_file == true" << std::endl;
  } else if (!(this->load_from_file)){
    std::cout << "Populating weights with random values" << std::endl;
    // main body should go here
  }
}



void NN::populate_random_biases(){
  if(this->load_from_file){
    std::cerr << "You are trying to populate biases with random values but load_from_file == true" << std::endl;
  } else if (!(this->load_from_file)){
    std::cout << "Populating biases with random values" << std::endl;
    // main body should go here
  }
}





