#include <iostream>
#include <vector>
#include "NN_basics.hpp"
#include "NN_training.hpp"
#include "NN_data_gen.hpp"

Training::Training(std::vector<std::vector<std::vector<double>>>* WeightsPtr,
                   std::vector<std::vector<double>>* NeuronsPtr,
                   std::vector<std::vector<double>>* BiasesPtr,
                   std::vector<coord>* TrainingDataPtr,
                   std::vector<std::vector<double>>* ZValuesPtr,
                   double LearningRate){
this-> WeightsPtr = WeightsPtr;
this-> NeuronsPtr = NeuronsPtr;
this-> BiasesPtr = BiasesPtr;
this-> TrainingDataPtr = TrainingDataPtr;
this-> LearningRate = LearningRate;
this-> ZValuesPtr = ZValuesPtr;
}

Training::Training(){
  std::cerr <<"You are trying to use the default constructor for Training which is not allowed" << std::endl;
}




void Training::run_TrainingOneLayer(int layer_index){
// imagine that you are at the first layer 
  //

  // for each neuron in the current layer 
  for (int i = 0 ; i < NeuronsPtr[layer_index].size() ; i++){




//////////////////////////////////// GENERAL SETUP FOR A NEURON  //////////////////////////////////////////


      // set dL_dA here so you don't continously loop through in calculating 
      // every single weight ... that would be a waste of time
      double dL_dA = 0;
      double dA_dZ = 0;

      //3 things to calculate!
      //1) dL_dA -> the derivative of the loss with respect to the activation
      //2) dA_dZ -> the derivative of the activation with respect to the raw input
      //3) dZ_dW_ij -> the derivative of the raw input with respect to the specific weight we are looking at



            // DERIVATIVE: dA_dZ 
            // this is a lot harder ... going to need to have the z value for the current layer_index at neuron j
            if (ZValuesPtr[layer_index - 1][i] <= 0){
              dA_dZ = 0; 
            } else {
              dA_dZ = 1;
            } 

            //DERIVATIVE: dL_dA
            // this one is only moderately loco
            // this one is the hardest and requires a sum function
            for (int i = 0 ; i < NeuronsPtr[layer_index].size() ; i++){
              dL_dA += (NeuronsPtr[layer_index][i] - TrainingDataPtr[this->TrainingIndexCtr].y );
            }
    
    
//really quickly we want to calculate the gradient for the bias of this neuron 
//////////////////////////////////// BIASES ///////////////////////////////////////////

double biasgradient = 0;


//DERIVATIVE: dZ_dBi
//this describes the relationship between the bias and the raw input function
dZ_dBi = 1



biasgradient = dL_dA * dA_dZ * dZ_dBi; 

    this->BiasesPtr[layer_index - 1][i] = biasgradient;









      // We want to:
      // 1) calculate dZ_dW_ij for the weight ij 
      // 2) multiply dZ_dW_ij dL_dA and dA_dZ 
      // 3) write that product to the gradient jagged array
      // for each weight for this specific neuron
      for (int j = 0 ; j < NeuronsPtr[layer_index - 1].size() ; j++){
      // initialize these values equal to zero ... they will only be used in this j for loop       
      double weightgradient = 0;
      double dZ_dW_ij = 0;

      // calculate the gradient for this weight
    weightgradient = dL_dA * dA_dZ * dZ_dW_ij;
    
    // actually do the assignment here
        // layer_index - 1 because GradientWeights has only four indexes whereas NeuronsPtr has 5
        // and then for the ith neuron inside of there
        // and finally for the jth weight
        this-> GradientWeights[layer_index - 1][i][j] = weightgradient;
    }// move to next neuron
  
// calculate the gradient for the bias of this neuron and write that


  }


}





void Training:run_BackpropOneTrainingExample(){
  //for each layer which has weights and biases to take gradients of
  for (int i = 5 ; i > 1 ; i--){
    
    //for each neuron in the layer that we are looking after
    for(int j = 0 ; j < this->NeuronsPtr[i] ; j++){
      // values to be shared 
      double dLt_dA = 0;
      double dA_dZ = 0;
      
      // when we are looking at the output layer
      if(i == 5){
        // calculate dLt_dA
        for(int h = 0 ; h < this->NeuronsPtr[i].size() ; h++){
          dLt_dA += this->NeuronsPtr[i][h] - this->TrainingDataPtr[TrainingIndexCtr].y;
        
        if(ZValuesPtr[i - 1][j] > 0){
          dA_dZ = 1;
        }
        
        }
      }

      // when we are looking at the remaining 3 layers
      else{


      }

      


      // value for bias always 1
      dz_dBi = 1;

      // write the value
      GradientBiasesPtr[i - 1][j] = dLt_dA * dA_dZ * dZ_dBi; 

      // for each weight that belongs to neuron j in layer i
      for(int k = 0 ; k < this->NeuronsPtr[i - 1] ; k++){
      // weight specific
      double dZ_dWjk = 0;
      
      // when we are looking at the output layer
      if(i == 5){
        dZ_dWjk = this->NeuronsPtr[i - 1][k]
      } 

      // for the remaining 3 layers
      else {

      }


      // write the value
      GradientWeightsPtr[i - 1][j][k] = 
      }
    }
  }
}


void Training::run_BackpropOneTrainingExample(){
  // run the training for each layer in the network that has weights and biases ... layers 2 - 5 excluding 1 because the first layer
  for (int i = 0 ; i < 4 ; i++){
    run_TrainingOneLayer(i + 1);
  }
    // after successfully completing the training for each layer at this training example ... increment the training TrainingIndexCtr
    this->TrainingIndexCtr ++;

}

// going to rewrite one layer and one example into one
void Training:run_BackpropOneTrainingExample(){
    
// BACKPROP EACH SET OF WEIGHTS AND BIASES:
// -> a set of weights and biases exist between two layer
// -> 5 total neuron layers ... so 4 sets contained in the network
// -> start at the last layer/output layer
// -> we start with the set between 4 and 4 + 1 ... and then move to the set between 3 and 3 + 1
for(int i = 4 ; i > 0 ; i--){
  // FOR ONE SET OF WEIGHTS AND BIASES:
  // -> the set between layer i and layer i + 1
  for(int j = 0 ; j < NeuronsPtr[i + 1] ; j++){
    //FOR EACH WEIGHT k  AND BIAS j IN THE SET
    


    //////// SHARED //////// -> partial derivatives used by both THE bias and EACH weight for neuron j in layer i + 1     
    double dLt_dA_j^ip1 = 0;


    double dA_jexpip1_dZ_jexpip1 = 0;

      // if we are on the output layer we need to evaluate the cost function
      // -> as we move deeper into the function I think that we need to revaluate dl_da for each weight ???
      if( i  ==  4){

        for(int h = 0 ; h < ; h++){
          dLt_dA_jexpip1 += (NeuronsPtr[i + 1][j] - TrainingDataPtr[this->TrainingIndexCtr].y);
        }

        if(ZValuesPtr[i][j] > 0){
          dA_jexpip1_dZ_jexpip1 = 1;
        }

      } 




    //////// FOR BIASES ONLY /////////
    double dZ_jexpip1_dB_jexpip1 = 1;
    

    // set the bias gradient
    GradientBiasesPtr[i][j] = dLt_dA_jexpip1 * dA_jexpip1_dZ_jexpip1 * dZ_jexpip1_dB_jexpip1; 
    // for each weight between the layer i and i + 1
    for(int k = 0 ; k < NeuronsPtr[i] ; k++){
    //////// FOR WEIGHTS ONLY //////////    
    double dZ_jexpip1_dW_jkexpip1 = NeuronsPtr[i][k];


    // if we are not looking at the connection between the 4th and output layer ... we want to do the following
    //
    if (i < 4){
        
    }

    GradientWeightsPtr[i][j] = dLt_dA_jexpip1 * dA_jexpip1_dZ_jexpip1 * dZ_jexpip1_dW_jkexpip1;


    }
  }
}


}




// function to run all the training for a specified amount of training examples
void Training::run_AllTraining(){
  // run training for the amount of training examples that there are
  for (int i = 0 ; i < this->TrainingDataPtr->size() ; i++){
      run_BackpropOneTrainingExample();
  }

}
