#include <iostream>
#include <vector>
#include <cmath>

// this program should be a very basic program that functions without really any outside output





class CreateData{
  public:
    std::vector<std::vector<double>> create_DataVectorM_X_B(double m, double b, int length){
      std::vector<std::vector<double>> X_Y(2, std::vector<double>(length));

      for (int i = 0 ; i < length ; i ++){
        X_Y[0][i] = i
      }

      for (int i = 0 ; i < length ; i++){
        X_Y[1][i] = (m * i) + b;
      }
      
      //
    return X_Y;

    }
};


class CreateNetwork{
  public:
    std::vector<double> create_OneNueronLayer(int qty){
      std::vector<double> CurrentLayer(qty);
      return CurrentLayer;
    }
    std::vector<std::vector<double> create_WeightsBetweenTwoLayers(int current_layer, int incoming_layer){
      std::vector<std::vector<double>> WeightsMatrixOneLayer(current_layer, incoming_layer);
      return WeightsMatrixOneLayer;
    }
    std::vector<double> create_BiasesOneLayer(){
      std::vector<double> BiasLayer(qty);
      return BiasLayer;
    }
    std::vector<std::vector<double>> create_NeuronsEntireNetwork5LayersVector(int input, int first, int second, int third, int output){
      std::vector<std::vector<double>> EntireNetworkVector(5);

      EntireNetworkVector[0] = create_OneNueronLayer(input);
      EntireNetworkVector[1] = create_OneNueronLayer(first);
      EntireNetworkVector[2] = create_OneNueronLayer(second);
      EntireNetworkVector[3] = create_OneNueronLayer(third);
      EntireNetworkVector[4] = create_OneNueronLayer(output);

      return EntireNetworkVector;
    }
    std::vector<std::vector<std::vector<double>>> create_AllWeights5Layers(int input, int first, int second, int third, int output){
      std::vector<std::vector<std::vector<double>>> VectorMatrixContainer(4);

      VectorMatrixContainer[0] = create_WeightsBetweenTwoLayers(first, input);
      VectorMatrixContainer[1] = create_WeightsBetweenTwoLayers(second, first);
      VectorMatrixContainer[2] = create_WeightsBetweenTwoLayers(third , second);
      VectorMatrixContainer[3] = create_WeightsBetweenTwoLayers(output, third);
    
      return VectorMatrixContainer;
    }
    std::vector<std::vector<double>> create_AllBiases5Layers(int input, int first, int second, int third, int output){
      std::vector<std::vector<double>> VectorContainer(4);

      VectorContainer[0] = create_BiasesOneLayer(first);
      VectorContainer[1] = create_BiasesOneLayer(second);
      VectorContainer[2] = create_BiasesOneLayer(third);
      VectorContainer[3] = create_BiasesOneLayer(output);

      return VectorContainer;
    }
};

class ForwardPropogation{
  public:
    
    double ReLU(double input){
      if (input > 0){
        return input;
      } else {
        return 0;
      }
    }

    double Sigmoid(double input){
      return 1.0 / (1.0 + exp(-input));
    }

    double DotProduct(std::vector<double> & vec1, std::vector<double> & vec2){
      if (vec1.size() != vec2.size()){
        std::cerr << "Vectors are not the same size for DotProduct function!";
        return 0;
      }else {
        double sum = 0;
        for (int i = 0 ; i < vec1.size(); i++){
          sum += vec1[i] * vec2[i];
        }
      }
    }

    void calculateANDwrite_NextLayerActivations(
                                           int index_IncomingLayer, 
                                           int index_CurrentLayer, 
                                           std::vector<std::vector<double>> & NeuronMatrix,
                                           const std::vector<std::vector<std::vector<double> & WeightsJaggedArray,
                                           const std::vector<std::vector<double>> & BiasesArray
                                           ){
    
    // for each neuron
    for (int i = 0; i < NeuronMatix[index_CurrentLayer].size(); i++){

      double raw_sum = DotProduct(NeuronMatrix[incoming_layer], WeightsJaggedArray[current_layer - 1][i]) + BiasesArray[index_CurrentLayer - 1][i];
      
      double activation = Sigmoid(raw_sum);

      NeuronMatrix[current_layer][i] = activation;

    }

    calculateANDwrite_AllActivationsAllLayers(      // should take in just the matrices and arrays
                                           std::vector<std::vector<double>> & NeuronMatrix,
                                           const std::vector<std::vector<std::vector<double> & WeightsJaggedArray,
                                           const std::vector<std::vector<double>> & BiasesArray
                                           ){
   calculateANDwrite_NextLayerActivations(0,
                                          1,
                                          NeuronMatrix,
                                          WeightsJaggedArray,
                                          BiasesArray); 
    
   calculateANDwrite_NextLayerActivations(1,
                                          2,
                                          NeuronMatrix,
                                          WeightsJaggedArray,
                                          BiasesArray); 
   calculateANDwrite_NextLayerActivations(2,
                                          3,
                                          NeuronMatrix,
                                          WeightsJaggedArray,
                                          BiasesArray); 
   calculateANDwrite_NextLayerActivations(3,
                                          4,
                                          NeuronMatrix,
                                          WeightsJaggedArray,
                                          BiasesArray); 


    }
};


class Backpropagation{
  public:
    calculate_RawCostFunctionOutPutLayer(
                                         const std::vector<std::vector<double>>& NeuronMatrix,
                                         const std::vector<std::vector<double>>& DataSet2X2,
                                         const int index_DataSet
                                         ){
    // look at the last row and calculate cost 
    

    }
};

class WriteToFile{
  public:
}


int main(){
  CreateNetwork INIT;
  CreateData DATA;
  WriteToFile WRITE;
  TrainNetwork TRAIN;

  // parameters for initializing NN
  int input = 2;
  int first = 10;
  int second = 10;
  int third = 10; 
  int output = 2;

  // parameters for training data
  double M;
  double B;
  int TrainingLength;




  // create network



  auto NeuronMatrix = create_NeuronsEntireNetwork5LayersVector(input, first, second, third, output);

  auto WeightsMatrixVector = create_AllWeights5Layers(input, first, second, third, output);

  auto BiasesMatrix = create_AllBiases5Layers(first, second, third, output); // input is skipped because input layer does not 
                                                                             // recieve biases

  

  // create training DATA



  // m, b , length of data vectors
  auto TrainingData = TRAIN.create_DataVectorM_X_B(M, B, TrainingLength );



  return 0;
}
