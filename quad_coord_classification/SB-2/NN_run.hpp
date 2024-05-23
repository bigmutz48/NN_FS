#ifndef NN_RUN_HPP
#define NN_RUN_HPP
#include "NN_init.hpp"

class NN_RUN{
      // constructor set parameters  
        std::string weights_file_name;
        std::string biases_file_name;
        std::string metadata_file_name;



  // methods for populating weights and biases from a file 
  void populate_weights_from_file(std::string weights_file_name);
  void populate_biases_from_file(std::string biases_file_name);
  void populate_metadata_from_file(std::string metadata_file_name);
  

  // create my object
    NN my_NN;
  
  // populate my object
    populate_weights_from_file(weights_file_name);
    populate_biases_from_file(biases_file_name);
    populate_metadata_from_file(metadata_file_name);


  // functions for forward prop



  public:
    NN_RUN(
        std::string weights_file_name,
        std::string biases_file_name,
        std::string metadata_file_name
        );


    

    NN get_NN();
    
  // functions that interact with the user and allow the user to test examples
    void run_user_interaction();


};




#endif
