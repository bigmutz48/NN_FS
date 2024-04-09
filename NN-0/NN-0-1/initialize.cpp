// include the NN header file 
#include <NN_initialize.h>


// standard libraries for this project
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

class NN_initialize {
  public:
    
    //these functions should allow the user to easily initialize 4 empty vectors where neuron activations can be stored

    std::vector<double>* create_InputLayer (int qty) {
      std::vector<double>* InputLayerPtr = new std::vector<double>(qty);
      return InputLayerPtr;
    }

    std::vector<double>* create_FirstLayer (int qty) {
      std::vector<double>* FirstLayerPtr = new std::vector<double>(qty);
      return FirstLayerPtr;
    }

    std::vector<double>* create_SecondLayer (int qty) {
      std::vector<double>* SecondLayerPtr = new std::vector<double>(qty);
      return SecondLayerPtr;
    }

    std::vector<double>* create_OutputLayer (int qty) {
      std::vector<double>* OutputLayerPtr = new std::vector<double>(qty);
      return OutputLayerPtr;
    }



    // these functions are supposed to help the user create the weights for each neuron and link them up
    std::vector<double>* create_WeightsToOneNeuron (int recieving) {
      std::vector<double>* WeightsToOneNeuronPtr = new std::vector<double>(recieving);
      return WeightsToOneNeuronPtr;
    // I would really like to store all the variables for each neuron in one vector or maybe in one matrix or an array of vectors
    //  -> it would be really nice if I i could somehow link each neuron to the weights and one bias that belongs to it ... this might prove nearly impossible though and could slow down the program speed
    }
    

    // call all functions to initialize the empty neural network
  //  void ..... // this might not actually work ... unless I return an array?


    // could also make a function to create a matrix of weights for one layer ??
    

    std::vector<std::vector<double>>* create_WeightsOneLayerMatrix (int incoming_layer, int current_layer) { // the return type is a pointer to a matrix (a vector full of vector<double>)
      std::vector<std::vector<double>>* WeightsOneLayerMatrixPtr = new std::vector<std::vector<double>>(current_layer , std::vector<double>(incoming_layer));
      return WeightsOneLayerMatrixPtr;
    }
    void set_MatrixOneLayer_ToRandom (std::vector<std::vector<double>>* MatrixPtr){
      
      // set up the random number generator
      srand(static_cast<unsigned int>(time(nullptr)));

      // return the amount of columns of the matrix
      int num_vectors = MatrixPtr->size();
      
      // return the amount of rows of the matrix
      int vector_size = MatrixPtr->at(0).size();


      // run the nested loops to randomize all the values
      for (int i = 0; i < num_vectors ; ++i ) {
        for (int j = 0; j< vector_size; ++j){
          // to each entry Matrix[i][j] ... assign a random value between -1 and 1
          (*MatrixPtr)[i][j] = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;
        }
      }
    }

};


int main () {
  // declare the variables that will store the amounts of neurons that each layer will contain!!!
  int Input = 1000;
  int First = 12;
  int Second = 12;
  int Output = 10;

  // create instance of NN_initialize class 

  NN_initialize NN;
  


  // create each layer using Ptrs!!!!
  std::vector<double>* InputLayerPtr = NN.create_InputLayer(Input);
  std::vector<double>* FirstLayerPtr = NN.create_FirstLayer(First);
  std::vector<double>* SecondLayerPtr = NN.create_SecondLayer(Second);
  std::vector<double>* OutputLayerPtr = NN.create_OutputLayer(Output);
  
  // create the weights for each layer!!!!
  
  // input -> first layer
  std::vector<std::vector<double>>* WeightsFirstLayerMatrixPtr = NN.create_WeightsOneLayerMatrix(Input, First);

  // first layer -> second layer
  std::vector<std::vector<double>>* WeightsSecondLayerMatrixPtr = NN.create_WeightsOneLayerMatrix(First, Second);

  // second layer -> output 
  std::vector<std::vector<double>>* WeightsOutputLayerMatrixPtr = NN.create_WeightsOneLayerMatrix(Second, Output);


  // randomize all weight matrices
  
  //has to be done for each matrix
  NN.set_MatrixOneLayer_ToRandom(WeightsFirstLayerMatrixPtr);
  NN.set_MatrixOneLayer_ToRandom(WeightsSecondLayerMatrixPtr);
  NN.set_MatrixOneLayer_ToRandom(WeightsOutputLayerMatrixPtr);


  return 0;
}
