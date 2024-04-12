#include <iostream>
#include <fstream>
#include <vector>


class initialize_NN{
  public:
    
    std::vector<double> create_BiasesOneLayer(int qty_CurrentLayer){
      std::vector<double> BiasLayer(qty_CurrentLayer);
      

      // set all to random numbers between 0 and 1  
      // seed random generator
      
      srand(static_cast<unsigned int>(time(nullptr)));

      // set each value in the vector to be random 
      for (int i = 0 ; i < qty_CurrentLayer ; i++){
        BiasLayer[i] = static_cast<double>(rand()) / RAND_MAX;
      }

      return BiasLayer;
    }
    
    std::vector<std::vector<double>> create_WeightsMatrixBetweenTwoLayers(int qty_CurrentLayer,
                                                                          int qty_IncomingLayer){
      std::vector<std::vector<double>> LayerWeights(qty_CurrentLayer, std::vector<double>(qty_IncomingLayer));
      


      // need to set each value in this matrix to a random value between one and zero 
      
      // seed random num generator
      srand(static_cast<unsigned int>(time(nullptr)));

      

      // set each value in the matrix to be a random value between 1 and 0
      for (int i = 0 ; i < qty_CurrentLayer ; i++){
        for (int j = 0 ; j < qty_IncomingLayer ; j++){
          LayerWeights[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
      }

      return LayerWeights;
    }

    std::vector<double> create_NeuronsOneLayer(int qty_CurrentLayer){
      std::vector<double> NeuronLayer(qty_CurrentLayer);
      return NeuronLayer;
    }





    

    // create the entire vector and subsquent matrices using the functions made earlier in the program.
    std::vector<std::vector<std::vector<double>>> create_VectorAllMatrixWeights(int qty_Input,
                                                                                int qty_First,
                                                                                int qty_Second,
                                                                                int qty_Third,
                                                                                int qty_Output){
      std::vector<std::vector<std::vector<double>>> AllLayersWeightMatrices(4);

      AllLayersWeightMatrices[0] = create_WeightsMatrixBetweenTwoLayers(qty_Input, qty_First); // weights matrix between input and first layer 
      AllLayersWeightMatrices[1] = create_WeightsMatrixBetweenTwoLayers(qty_First, qty_Second); // weight matrix between first and second layers 
      AllLayersWeightMatrices[2] = create_WeightsMatrixBetweenTwoLayers(qty_Second, qty_Third); // weight matrix between second and third layers 
      AllLayersWeightMatrices[3] = create_WeightsMatrixBetweenTwoLayers(qty_Third, qty_Output); // weight matrix between third and output layers
    


      return AllLayersWeightMatrices;
    }
    
    // create the matrix that will store the activations that are read for each neuron in each layer.
    std::vector<std::vector<double>> create_NeuronLayersMatrix(                 int qty_Input,
                                                                                int qty_First,
                                                                                int qty_Second,
                                                                                int qty_Third,
                                                                                int qty_Output){
    
      std::vector<std::vector<double>> NeuronLayersMatrix(5);

      NeuronLayersMatrix[0] = std::vector<double>(qty_Input);
      NeuronLayersMatrix[1] = std::vector<double>(qty_First);
      NeuronLayersMatrix[2] = std::vector<double>(qty_Second);
      NeuronLayersMatrix[3] = std::vector<double>(qty_Third);
      NeuronLayersMatrix[4] = std::vector<double>(qty_Output);
      

      return NeuronLayersMatrix;
    }
    // create the matrix that will contain all biases.
    std::vector<std::vector<double>> create_BiasesAllLayersMatrix(              int qty_Input,
                                                                                int qty_First,
                                                                                int qty_Second,
                                                                                int qty_Third,
                                                                                int qty_Output){
      std::vector<std::vector<double>> BiasesMatrix(5);

      BiasesMatrix[0] = std::vector<double>(qty_Input);
      BiasesMatrix[1] = std::vector<double>(qty_First);
      BiasesMatrix[2] = std::vector<double>(qty_Second);
      BiasesMatrix[3] = std::vector<double>(qty_Third);
      BiasesMatrix[4] = std::vector<double>(qty_Output);

      return BiasesMatrix;
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
