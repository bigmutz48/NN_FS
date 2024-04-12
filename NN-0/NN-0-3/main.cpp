#include <iostream>
#include <fstream>
#include <vector>


class initialize_NN{
  public:
    
    std::vector<double> create_BiasesOneLayer(int qty_CurrentLayer){

    }
    
    std::vector<std::vector<double>> create_WeightsMatrixBetweenTwoLayers(int qty_CurrentLayer){
      
    }

    std::vector<double> create_NeuronsOneLayer(int qty_CurrentLayer){

    }





    

    // create the entire vector and subsquent matrices using the functions made earlier in the program.
    std::vector<std::vector<std::vector<double>>> create_VectorAllMatrixWeights(int qty_Input,
                                                                                int qty_First,
                                                                                int qty_Second,
                                                                                int qty_Third,
                                                                                int qty_Output){
      
    }
    
    // create the matrix that will store the activations that are read for each neuron in each layer.
    std::vector<std::vector<double>> create_NeuronLayersMatrix(                 int qty_Input,
                                                                                int qty_First,
                                                                                int qty_Second,
                                                                                int qty_Third,
                                                                                int qty_Output){


    }
    // create the matrix that will contain all biases.
    std::vector<std::vector<double>> create_BiasesAllLayersMatrix(              int qty_Input,
                                                                                int qty_First,
                                                                                int qty_Second,
                                                                                int qty_Third,
                                                                                int qty_Output){


    }
    

};


class run_ForwardPropagation{
  public:
};


class run_BackPropagation{
  public:
};

class WriteToFile{
  public:
};

int main(){
  int input;
  int hidden1;
  int hidden2;
  int hidden3;
  int output;



  initialize_NN INIT;
  WriteToFile WRITETO;
  run_ForwardPropagation RUNFORWARD;
  run_BackPropagation RUNBACK;




  return 0;
}
