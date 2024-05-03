#include <iostream>
#include "NN_basics.hpp"
#include <fstream>
#include <vector>
#include <random>

// main class for initializing the init_NN


class init_NN {
    // seed a random number generator 
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(0,5);


    
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
    

    // we want each weight in this layer to be a random value and not 0
    // should assign a random double between 0 and 5
      for (int i = 0 ; i < current ; i++){
        for (int j = 0 ; j < incoming ; j++){
          int rand = distr(gen);
          main[i][j] = static_cast<double>(rand);
        }
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



    // parameters to be set when the constructor is called

    int qty_InputLayer = 0;
    int qty_FirstLayer = 0;
    int qty_SecondLayer = 0;
    int qty_ThirdLayer = 0;
    int qty_OutputLayer = 0;


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
            int output){
      if (input != 0 && first != 0 && second != 0 && third != 0 && output != 0){
      this->qty_InputLayer = input;
      this->qty_FirstLayer = first;
      this->qty_SecondLayer = second;
      this->qty_ThirdLayer = third; 
      this->qty_OutputLayer = output;
      } else {
        std::cerr << "Your forgot to set a parameter for the init_NN constructor - there are 5....\n"
                  << "input, first, second, third, output ....\n"
                  << "Each of these represents the amount of neurons in a respective layer" << std::endl;
      }
    }

    // default constructor in case you make some mistake and forget to properly initialize this mf
    init_NN(){
      std::cerr << "You cannot use the default constructor for creating an object of this class";
    }


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


class ForwardProp{

  double calculate_ActivationBetweenTwoLayers(){

  }


  // items to be set when the constructor is called

  // pointer to the weights
  std::vector<std::vector<std::vector<double>>>* WeightsPtr = nullptr;

  // pointer to the biases
  std::vector<std::vector<double>>* BiasesPtr = nullptr;

  // pointer to the neruons array
  std::vector<std::vector<double>>* NeuronsPtr = nullptr;
//private
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//public
  public:
  // constructor
  ForwardProp( std::vector<std::vector<std::vector<double>>>* WeightsPtr,
               std::vector<std::vector<double>>* BiasesPtr,
               std::vector<std::vector<double>>* NeuronsPtr){
    this->WeightsPtr = WeightsPtr;
    this->BiasesPtr = BiasesPtr;
    this->NeuronsPtr = NeuronsPtr;

  }
  // if default constructor is used throw an error
  ForwardProp(){
    std::cerr << "You cannot use the default constructor for ForwardProp";
  }

  void run_ForwardProp(){
      if (BiasesPtr = nullptr){
        std::cerr << "Must set BiasesPtr" << std::endl;
      } else if (WeightsPtr = nullptr){
        std::cerr << "Must set WeightsPtr" << std::endl;
      } else if (NeuronsPtr = nullptr){
        std::cerr << "Must set NeuronsPtr" << std::endl;
      } else {
        // if none of those get tripped then you want to run the forward prop

      }
    }
};
