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


class NN_ForwardPropagation{
  public:
    double ReLU(const double raw_input){
      if (raw_input < 0){
        return 0;
      } else {
        return raw_input;
      }
      return val;
    }
    double DotProduct(const std::vector<double> vec1,const std::vector<double> vec2){
      // return error if vectors not same size
      if (vec1.size() != vec2.size()){
        std::cerr << "Vectors not the same size for DotProduct function";
        return 0;
      }
        double val = 0;
      for (int i = 0 ; i < vec1.size() ; i++){
        val += vec1[i] * vec2[i];
      }

      return val;
    }
    void calculateandwrite_NextLayerActivations( 
                                                 const int index_CurrentLayer,

                                                 // make sure to pass by reference to these two when calling the function
                                                 const std::vector<std::vector<std::vector<double>>>& WeightMatrixVector,
                                                 const std::vector<std::vector<double>>& BiasesMatrix,

                                                 // make sure to pass in a memory address to this guy
                                                 std::vector<std::vector<double>>* NeuronLayersActivationsMatrixPtr){
      for (int i = 0 ; i < NeuronLayersActivationsMatrixPtr->at(index_CurrentLayer).size() ; i++){ // run for the amount of neurons that are in this layer
        // main loop to write to current layer's neuron activations
        

        // take the dot product between the weights vector of the current neuron in our layer
        // and the vector of the neuron activations from the previous layer
        double OneNeuronRaw = DotProduct(WeightMatrixVector[index_CurrentLayer][i], NeuronLayersActivationsMatrixPtr[index_CurrentLayer - 1]);
        
        // add the bias to the raw output 
        double RawWithBias = OneNeuronRaw + BiasesMatrix[index_CurrentLayer][i];

        double ValueToWrite = ReLU(RawWithBias); // put the final output through ReLU
        
        // now actually write this value to the main vector
        // NeuronLayersActivationsMatrix[index_CurrentLayer][i]
        // access the current layer, and the Ith neuron in that layer's vector
        (*NeuronLayersActivationsMatrixPtr)[index_CurrentLayer][i] = ValueToWrite; // I think I did this right???
        }


    }
};

// going to use stochastic gradient descent or mini-batch gradient descent
class NN_Training{
  public:
    double calculate_SGD(){

    }
    double calculate_AverageCost(){

    }
    void calculateandwrite_WeightAndBiasUpdates(){

    }
};

class WriteToFile{
  public:
};


class ImageToComputerVision{
  public:
};

int main(){
  int input = 784;
  int hidden1 = 12;
  int hidden2 = 12;
  int hidden3 = 12;
  int output = 10;



  initialize_NN INIT;
  WriteToFile WRITETO;
  run_ForwardPropagation RUNFORWARD;
  run_BackPropagation RUNBACK;


  // initialize the network
  auto AllNeuronsMatrix = INIT.create_NeuronLayersMatrix(input, hidden1, hidden2, hidden3, output);

  // create weights matrix
  auto WeightMatrixVector = INIT.create_VectorAllMatrixWeights(input, hidden1, hidden2, hidden3, output);

  // create biases matrix
  auto BiasesMatrix = INIT.create_BiasesAllLayersMatrix(input, hidden1, hidden2, hidden3, output);

  return 0;
}
