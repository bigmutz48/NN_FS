#include <iostream>







class Initialize_NN{
  public:
    std::vector<std::vector<double>> create_JaggedArrayNeurons(const init_5layersnetwork& InitVals){
      std::vector<std::vector<double>> NeuronArray[5];




      // create all the vectors and initialize their values to zero
      std::vector<double> Input(InitVals.Input, 0.0);
      std::vector<double> First(InitVals.First, 0.0);
      std::vector<double> Second(InitVals.Second, 0.0);
      std::vector<double> Third(InitVals.Third, 0.0);
      std::vector<double> Output(InitVals.Output, 0.0);

      // 
      NeuronArray[0].push_back(Input);
      NeuronArray[1].push_back(First);
      NeuronArray[2].push_back(Second);
      NeuronArray[3].push_back(Third);
      NeuronArray[4].push_back(Output);



      return NeuronArray;
    }

    std::vector<std::vector<double>> create_WeightsMatrixBetweenLayers(const int index_CurrentLayer,
                                                                       const std::vector<std::vector<double>>& NeuronArray){
      
    }
    


    std::vector<std::vector<std::vector<double>>> create_ArrayAllWeights(const std::vector<std::vector<double>>& NeuronArray){
      std::vector<std::vector<std::vector<double>>> AllWeights[4];

      for (int i=0 ; i < 4; i++){
        AllWeights
      }

      return AllWeights;
    }

};

