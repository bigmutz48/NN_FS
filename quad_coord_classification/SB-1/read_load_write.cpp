#include "read_load_write.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

class ReadWrite{
  

void write_Weights(const std::string& filename, const std::vector<std::vector<std::vector<double>>>* Weights){
  std::ofstream FILEOUT(filename + "_Weights.txt");
  if(!FILEOUT){
    std::cerr << "Failed to open file";
  }
  
}

void write_Biases(const std::string& filename, const std::vector<std::vector<double>>* Biases){
  std::ofstream FILEOUT(filename + "_Biases.txt");
  if(!FILEOUT){
    std::cerr << "failed to open / create file";
  }
  

}





//private
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//public
  public:
 

  // to set the filename
  std::string filename = "NONE";



  // to tell the program where the weights are
  std::vector<std::vector<std::vector<double>>>* WeightsPtr = nullptr;
  

  // to tell the program where the biases are
  std::vector<std::vector<double>>* BiasesPtr = nullptr;


  

/* this function is supposed to take a filename string and two pointers and write the weights and biases to the filename 
 * creating two seperate files*/
  void write_ALL(const std::string& filename, 
                 const std::vector<std::vector<std::vector<double>>>* Weights,
                 const std::vector<std::vector<double>>* Biases){
    
    if (filename == "NONE"){
      std::cerr << "You did not set the filename" << std::endl;
    }
    if (WeightsPtr == nullptr){
      std::cerr << "Weights must be set" << std::endl;
    }
    if (BiasesPtr == nullptr){
      std::cerr << "Biases must be set" << std::endl;
    }
    if (BiasesPtr != nullptr && WeightsPtr != nullptr && filename != "NONE" ){
    write_Biases(filename, Biases);
    write_Weights(filename, Weights);
    }
  }


 

  

  };
