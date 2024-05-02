#include <iostream>
#include "NN_basics.hpp"
#include <fstream>
#include <vector>

// main class for initializing the init_NN


class init_NN {

    
    // functions to generate the network and allocate memory for it

    std::vector<double> create_OneLayer(int size){
      return std::vector<double>(size, 0);
    }


   std::vector<std::vector<double>> create_5LayerNetwork(int input, int first, int second, int third, int output){
    std::vector<std::vector<double>> ret(5);
    ret[0] = create_OneLayer(input);
    ret[1] = create_OneLayer(first);
    ret[2] = create_OneLayer(second);
    ret[3] = create_OneLayer(third;
    ret[4] = create_OneLayer(output);
   
    
    return ret;
    }
  

    // function to create the matrix for one neuron in the current layer
  std::vector<std::vector<double>> create_WeighsMatrixOneLayer(int incoming, int current){
  std::vector<std::vector<double>> main(current);
    for (int i = 0 ; i < current ; i++){
    // each spot in main gets an array the size of the incoming layer  
    main[i] = std::vector<double>(incoming, 0); 

    }
    
    ret main;


  }

    // create one set of weights

  std::vector<std::vector<std::vector<double>>> create_WeightsMain(int input, int first, int second, int third, int output){
    std::vector<std::vector<std::vector<double>>> WeightsMain(4);
    // fill up the layers
    
    // weights matrix between the input and first layer
    WeightsMain[0] = create_WeighsMatrixOneLayer(input, first);
    
    // weights matrix between the input and first layer
    WeightsMain[1] = create_WeighsMatrixOneLayer(first, second);
   
    // weights matrix between the input and first layer
    WeightsMain[2] = create_WeighsMatrixOneLayer(second, third);
    
    // weights matrix between the input and first layer
    WeightsMain[3] = create_WeighsMatrixOneLayer(third, output);
  }
  


  std::vector<std::vector<double>> create_Biases(int input, int first, int second, int third, int output){
    std::vector<std::vector<double> Biases(4);
    Biases = std::vector<double>(qty_FirstLayer, 1);
    Biases = std::vector<double>(qty_SecondLayer, 1);
    Biases = std::vector<double>(qty_ThirdLayer, 1);
    Biases = std::vector<double>(qty_OutputLayer, 1);
  
  return Biases;
  }

//private
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//public
  public: 
    // all of these are things that need to be accessed by whoever 

    // parameters to be set

    int qty_InputLayer = 0;
    int qty_FirstLayer = 0;
    int qty_SecondLayer = 0;
    int qty_ThirdLayer = 0;
    int qty_OutputLayer = 0;

    // create the objects to be accessed
    
    // create weights main  
    std::vector<std::vector<std::vector<double>>> WeightsMain = create_WeightsMain(qty_InputLayer,
                                                                                   qty_FirstLayer, 
                                                                                   qty_SecondLayer,
                                                                                   qty_ThirdLayer,
                                                                                   qty_OutputLayer)
    
    // create biases 
    std::vector<std::vector<double>> BiasesMain = create_Biases(qty_InputLayer,
                                                                qty_FirstLayer,
                                                                qty_SecondLayer,
                                                                qty_ThirdLayer,
                                                                qty_OutputLayer)




    // create neurons
    std::vector<std::vector<double>> NeuronsMain = create_5LayerNetwork(qty_InputLayer,
                                                                        qty_FirstLayer,
                                                                        qty_SecondLayer,
                                                                        qty_ThirdLayer,
                                                                        qty_OutputLayer)   
      
};
