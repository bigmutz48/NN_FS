#include <iostream>
#include <vector>
#include <fstream>


// 1) set up the empty neurons with pointers
// 2) set up the bias and weight vectors with random values
class initialize_NN{
  public:
    // create one layer 
    std::vector<double>* create_HiddenLayer(int qty){
    }
    
    std::vector<double>* create_BiasesOneLayer(){

    }

    std::vector<std::vector<double>>* create_WeightsOneLayer(){

    }
    

    // initialize all layers
    void init_ALL(){

    }

};

// 1) write weights and biases to an external file
class WriteToFile{
  public:
};

// 1) run forward propagation for given weights, bias, and input neuron activations
class run_ForwardPropagation{
  public:
};


// 1) run backpropagation to adjust weights and biases
class run_BackPropagation{
  public:
};


int main(){
  // assign these values before running the program
  int input;
  int layerX;
  int layerY;
  int layerz;
  int output;


  // class declarations / instance creation
  initialize_NN INIT;
  WriteToFile WRITETO;
  run_ForwardPropagation RUNFORWARD;
  run_ForwardPropagation RUNBACK;


  return 0;
}
