#ifndef NN_BASICS_HPP
#define NN_BASICS_HPP



#include <iostream>
#include "NN_basics.hpp"
#include <fstream>
#include <vector>
#include <random>


class math{
    //dot product
    double dot_product(const std::vector<double>& vec1, const std::vector<double>& vec2);

    // Relu activation funtion
    double ReLU(double raw_input);
  
};





// main class for initializing the init_NN


class init_NN {
    // seed a random number generator 
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<> distr;


    
    // functions to generate the network and allocate memory for it

    std::vector<double> create_OneLayer(int size);


   std::vector<std::vector<double>> create_5LayerNetwork(int input, int first, int second, int third, int output);
  

    // function to create the matrix for one neuron in the current layer
  std::vector<std::vector<double>> create_WeighsMatrixOneLayer(int incoming, int current);

    // create one set of weights

  std::vector<std::vector<std::vector<double>>> create_WeightsMain(int input, int first, int second, int third, int output);
  


  std::vector<std::vector<double>> create_Biases(int input, int first, int second, int third, int output);



  std::vector<std::vector<double>> create_ZVal_storage();

    // parameters to be set when the constructor is called

    int qty_InputLayer;
    int qty_FirstLayer;
    int qty_SecondLayer;
    int qty_ThirdLayer;
    int qty_OutputLayer;


//private
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//public
  public: 
    // all of these are things that need to be accessed by whoever 

    // constructor for this class 
    init_NN(int input,
            int first,
            int second,
            int third, 
            int output);

    // default constructor in case you make some mistake and forget to properly initialize this mf
    init_NN();


    // create the objects to be accessed
    
    
    // create weights main  
    std::vector<std::vector<std::vector<double>>> WeightsMain; 
    
    // create biases 
    std::vector<std::vector<double>> BiasesMain; 

    // create neurons
    std::vector<std::vector<double>> NeuronsMain;   
      
};


class ForwardProp{




  // items to be set when the constructor is called

  // pointer to the weights
  std::vector<std::vector<std::vector<double>>>* WeightsPtr;

  // pointer to the biases
  std::vector<std::vector<double>>* BiasesPtr;

  // pointer to the neruons array
  std::vector<std::vector<double>>* NeuronsPtr;

  // pointer to the z values / the raw inputs to the neurons ... this is needed for the calculus that will be done
  std::vector<std::vector<double>>* ZValuesPtr;


  void calculateandwrite_ActivationsNextLayer(int index_CurrentLayer);


  // create the function that will fill up ZValuesPtr 
  std::vector<std::vector<double>>* create_ZVal_storage();

//private
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//public
  public:
  // constructor
  ForwardProp( std::vector<std::vector<std::vector<double>>>* WeightsPtr,
               std::vector<std::vector<double>>* BiasesPtr,
               std::vector<std::vector<double>>* NeuronsPtr);
  // if default constructor is used throw an error
  ForwardProp();




  // main function to be called to run all forward prop
  void run_ForwardProp();



};

#endif
