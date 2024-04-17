#include <iostream>
#include <vector>

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




class TrainNetwork{
  public:
    calculate_RawCostFunction(){

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


  int input = 2;
  int first = 10;
  int second = 10;
  int third = 10; 
  int output = 2;


  // create network



  auto NeuronMatrix = create_NeuronsEntireNetwork5LayersVector(input, first, second, third, output);

  auto WeightsMatrixVector = create_AllWeights5Layers(input, first, second, third, output);

  auto BiasesMatrix = create_AllBiases5Layers(first, second, third, output); // input is skipped because input layer does not 
                                                                             // recieve biases

  

  // create training DATA


  


  return 0;
}
