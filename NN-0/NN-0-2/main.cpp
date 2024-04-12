#include <iostream>
#include <vector>
#include <fstream>

// 1) set up the empty neurons with pointers
// 2) set up the bias and weight vectors with random values
class initialize_NN{
  public:



    // create one layer 
    std::vector<double>* create_NeuronsOneLayerPtr(int qty_CurrentLayer){
      std::vector<double>* NeuronLayerPtr = new std::vector<double>(qty_CurrentLayer);
      return NeuronLayerPtr;
    }
    
    std::vector<double>* create_BiasesOneLayerPtr(int qty_CurrentLayer){
        std::vector<double>* BiasVectorPtr = new std::vector<double>(qty_CurrentLayer); 
        
         srand(static_cast<unsigned int>(time(nullptr)));// seed the random num generator

        for (int i = 0; i < BiasVectorPtr->size()){ // set each bias to a random value when the system is first created
          (*BiasVectorPtr)[i] = static_cast<double>(rand()) / RAND_MAX; 
        }
        return BiasVectorPtr;
    }

    std::vector<std::vector<double>>* create_WeightsBetweenTwoLayersPtr(int qty_CurrentLayer, int qty_IncomingLayer){
      std::vector<std::vector<double>>* WeightsMatrixPtr = new std::vectors<std::vector<double>>(qty_CurrentLayer, std::vector<double>(qty_IncomingLayer));

      // set each value to be random
      
      // seed the random generator first
      srand(static_cast<unsigned int>(time(nullptr)));

      // go through each weight entry and set it to be random
      for (int i = 0 ; i < WeightsMatrixPtr->size(); i++){
        for (int j = 0; j < WeightsMatrixPtr->at(0).size(); j++){ // set each value in WeightsMatrix to be a random 
                                                                  // number between 0 and 1
          (*WeightsMatrixPtr)[i][j] = static_cast<double>(rand()) / RAND_MAX;  // might be better to do this 
                                                                                            // using % mod function
        }
      }
  
    // return the Ptr so that the matrix can be found
    return WeightsMatrixPtr;

    }
    
    
    std::vector<std::vector<double>>* CREATEALLNEURONSPTR(int qty_InputLayer,
                                                                       int qty_FirstLayer,
                                                                       int qty_SecondLayer,
                                                                       int qty_ThirdLayer,
                                                                       int qty_OutputLayer
        
        ){
      std::vector<std::vector<double>>* AllLayersNeuronVectorsPtr = new std::vector<std::vector<double>>(5); // make the main vector that 
                                                                                                                                       // will hold the big vectors for each layer
    // each layer gets a create layer value
    AllNeuronsActivationsMatrixPtr[0] = create_NeuronsOneLayer(qty_InputLayer);
    AllNeuronsActivationsMatrixPtr[1] = create_NeuronsOneLayer(qty_FirstLayer);
    AllNeuronsActivationsMatrixPtr[2] = create_NeuronsOneLayer(qty_SecondLayer);
    AllNeuronsActivationsMatrixPtr[3] = create_NeuronsOneLayer(qty_ThirdLayer);
    AllNeuronsActivationsMatrixPtr[4] = create_NeuronsOneLayer(qty_OutputLayer);
    // now each space in AllNeuronsActivationsMatrixPtr should contain the NeuronLayerPtr for each layer

    
    }



    std::vector<std::vector<std::vector<double>>>* CREATEALLWEIGHTSPTR (int qty_InputLayer,
                                                                        int qty_FirstLayer,
                                                                        int qty_SecondLayer,
                                                                        int qty_ThirdLayer,
                                                                        int qty_OutputLayer){
      // create the first vector that holds the each layer
      std::vector<std::vector<std::vector<double>>>* AllLayersWeightsMatrixPtr = new std::vector<std::vector<std::vector<double>>>(5);

      // each of index of these vectors must be populated with a vector (representing a layer) that itself contains a vector (the weights for a given neuron)
      
      // for the weights between input and first layer 
      for (int i = 0 ; i < qty_FirstLayer ; i++){
        for (int j = 0 ; j < qty_InputLayer ; j++){

        }
      }
    }
    


};

// 1) write weights and biases to an external file
class WriteToFile{
  public:
};

// 1) run forward propagation for given weights, bias, and input neuron activations
class run_ForwardPropagation{
  public:  
    double ReLU(double raw_input){
    return ans;
    }
    void write_ActivationsNextLayer(int IncomingLayerINDEX,
                                    int CurrentLayerNumberINDEX,
                                    std::vector<std::vector<double>>* WeightsMatrixPtr,
                                    std::vector<double>* BiasVectorPtr,
                                    std::vector<std::vector<double>>* AllNeuronsActivationsMatrixPtr; 
                                    ){

   // calculate the activations of each of the current layer neurons 
    for (int i = 0 ; i < qty_CurrentLayer ; i++){ // for each nueron in the current layer

      
    }




    }
};


// 1) run backpropagation to adjust weights and biases
class run_BackPropagation{
  public:
};


int main(){
  // assign these values before running the program
  int input;
  int hidden1;
  int hidden2;
  int hidden3;
  int output;


  // class declarations / instance creation
  initialize_NN INIT;
  WriteToFile WRITETO;
  run_ForwardPropagation RUNFORWARD;
  run_ForwardPropagation RUNBACK;


  return 0;
}
