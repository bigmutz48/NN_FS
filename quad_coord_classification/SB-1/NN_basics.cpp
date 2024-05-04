#include <iostream>
#include "NN_basics.hpp"
#include <fstream>
#include <vector>
#include <random>



    //dot product
double math::dot_product(const std::vector<double>& vec1, const std::vector<double>& vec2){
      double sum = 0;
      if (vec1.size() != vec2.size){
        std::cerr << "Vectors not the same size for dot product" << std::endl;
      } else{
        for (int i = 0 ; i < vec1.size() ; i++){
          sum += vec1[i] * vec2[i];
        }

      }

      // return the value
      return sum;

    }


double math::ReLU(double raw_input){
      if (raw_input < 0){
        return 0.0;
      } else (
          return raw_input;
          )

    }






// main class for initializing the init_NN





    
    // functions to generate the network and allocate memory for it

    std::vector<double> init_NN::create_OneLayer(int size){
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
  std::vector<std::vector<double>> init_NN::create_WeighsMatrixOneLayer(int incoming, int current){
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

  std::vector<std::vector<std::vector<double>>> init_NN::create_WeightsMain(int input, int first, int second, int third, int output){
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
  


  std::vector<std::vector<double>> init_NN::create_Biases(int input, int first, int second, int third, int output){
    std::vector<std::vector<double> Biases(4);
    Biases = std::vector<double>(qty_FirstLayer, 1);
    Biases = std::vector<double>(qty_SecondLayer, 1);
    Biases = std::vector<double>(qty_ThirdLayer, 1);
    Biases = std::vector<double>(qty_OutputLayer, 1);
  
  return Biases;
  }



    // parameters to be set when the constructor is called




//private
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//public
    // all of these are things that need to be accessed by whoever 

    // constructor for this class 
init_NN::init_NN(int input,
            int first,
            int second,
            int third, 
            int output)
// initalizer list
  : gen(rd()), distr(0, 5)


{
// do i need to do this? ...
// seems safe to do this just in case
    this-> qty_InputLayer = 0;
    this-> qty_FirstLayer = 0;
    this-> qty_SecondLayer = 0;
    this-> qty_ThirdLayer = 0;
    this-> qty_OutputLayer = 0;


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
    

      
    // seed a random number generator 
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(0,5);


    
    // create weights main  
    this-> WeightsMain = create_WeightsMain(qty_InputLayer,
                                                                                   qty_FirstLayer, 
                                                                                   qty_SecondLayer,
                                                                                   qty_ThirdLayer,
                                                                                   qty_OutputLayer)
    
    // create biases 
    this-> BiasesMain = create_Biases(qty_InputLayer,
                                                                qty_FirstLayer,
                                                                qty_SecondLayer,
                                                                qty_ThirdLayer,
                                                                qty_OutputLayer)




    // create neurons
    this-> NeuronsMain = create_5LayerNetwork(qty_InputLayer,
                                                                        qty_FirstLayer,
                                                                        qty_SecondLayer,
                                                                        qty_ThirdLayer,
                                                                        qty_OutputLayer)   
    }









    // default constructor in case you make some mistake and forget to properly initialize this mf
init_NN::init_NN(){
      std::cerr << "You cannot use the default constructor for creating an object of this class";
    }



  void ForwardProp::calculateandwrite_ActivationsNextLayer(int index_CurrentLayer){

    for (int i = 0 ; i < this -> WeightsPtr[index_CurrentLayer].size() ; i++){
     // populate the neuron in the next layer appropritely
      this -> NeuronsPtr[i + 1][j] = math::ReLU((math::dot_product(WeightsPtr[i][j], NeuronsPtr[i]));
    }
  }


//private
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//public

  // constructor
  ForwardProp::ForwardProp( std::vector<std::vector<std::vector<double>>>* WeightsPtr,
               std::vector<std::vector<double>>* BiasesPtr,
               std::vector<std::vector<double>>* NeuronsPtr){
    this->WeightsPtr = WeightsPtr;
    this->BiasesPtr = BiasesPtr;
    this->NeuronsPtr = NeuronsPtr;

  }
  // if default constructor is used throw an error
  ForwardProp::ForwardProp(){
    std::cerr << "You cannot use the default constructor for ForwardProp";
  }

  void ForwardProp::run_ForwardProp(){
      if (BiasesPtr == nullptr){
        std::cerr << "Must set BiasesPtr" << std::endl;
      } else if (WeightsPtr == nullptr){
        std::cerr << "Must set WeightsPtr" << std::endl;
      } else if (NeuronsPtr == nullptr){
        std::cerr << "Must set NeuronsPtr" << std::endl;
      } else {
        // if none of those get tripped then you want to run the forward prop 
        

        // loop for the remaining layers which remain unfilled ... only 2,3,4,5 remain unfilled  and therefore are the only ones that 
        // require filling so four loops is sufficient
        for (int i = 0 ; i < 4 ; i++){
          calculateandwrite_ActivationsNextLayer(i);
        }
      }
      std::cout << "run_ForwardProp successful!" << std::endl;
    }
