// this file should be responsible for finding neuron activations for given weights, biases ... and input neuron activations

#include <iostream>
#include <vector>

// RELu

double ReLU(double raw_input){ // basic RELu function
  if (raw_input <= 0){ 
    return int ans = 0;
  } else if(raw_input > 0){
    return raw_input;
  }
}


double dot_product(std::vector<double>* vec1Ptr, std::vector<double>* vec2Ptr){ // simple function to compute dot product between two vecs
  double ans;
  for (int i = 0; i < vec1Ptr->size(); ++i){
    ans += (*vec1Ptr)[i] * (*vec2Ptr)[i]; // compute the dot product between two entries
  }

return ans;

}



// raw output function to be run in a for loop
double activation_ithNeuron(std::vector<std::vector<double>>* CurrentLayerWeightsMatrixPtr, // weight matrix for the layer currently being evaluated 
                              std::vector<double>* CurrentLayerBiasesPtr, // vector of biases for current layer
                              std::vector<double>* PreviousLayerActivationsPtr, // vector of previous layer activations
                              int ithNeuron) // this function should run in a for loop and this will be essentially 
                                                         // where i goes. this tell this function
                                                         // which neuron in the layer we are currently on
                      {
                        double Neuron_RawSum;
                        double Neuron_RawSum_wBias;
                        double ReLU_FinalActivation;

                        // find raw sum activation
                        // should be the dot product between the ith's neurons weight vector and the previous layer's neuron activation vector
                        Neuron_RawSum = dot_product(CurrentLayerWeightsMatrixPtr[ithNeuron] , PreviousLayerActivationsPtr); // take vector pointers don't forget!!!
                        Neuron_RawSum_wBias = Neuron_RawSum + (*CurrentLayerBiasesPtr)[ithNeuron]; // with biases

                        ReLU_FinalActivation = ReLU(Neuron_RawSum_wBias);

                        return ReLU_FinalActivation;
                      } 
