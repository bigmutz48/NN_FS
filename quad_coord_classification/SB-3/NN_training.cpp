#include "NN_training.hpp"
#include "NN_create_training_data"



#include <iostream>
// default constructor should throw an error






NN_training::NN_training(){
  std::cout << "You are trying to use the default constructor for NN_training which is not allowed" << std::endl;
}

//nondefault constructor
NN_training::NN_training(NN& network_to_train, training_data& my_training_data):

  // member initializer list for this constructor
NN_to_train(network_to_train),
my_training_data(my_training_data){
  // not sure that this constructor needs to do anything passed this
}

~NN_training::NN_training(){}



// should take no parameters .... uses this->
void NN_training::calculate_partials_for_current_training_example(){

struct neuron_partials{
    // main partials 

      // partial between this neurons a and this neurons z
      double dai_dzi;
      // partial between cost and this a 
      double dc_dai;
      


      // vector of weights partials
      std::vector<double> dzi_dwi_vec;

      // partial between this z and this b always equals 1 
      double dzi_dbi = 1;

      // partial beteen this z (layer n) and the a from the previous layer (layer n - 1)
      double dzi_dai_nminus1;


};
    // look at the output
    for (int i = 0 ; i < this->NN_to_train.get_output_layer().size() ; i++){
      // each neuron's partials 
      if (this->NN_to_train.get_output_layer()[i].z > 0){
      this->partials_output_layer[i].dai_dzi = 1; 
      } else {
      this->partials_output_layer[i].dai_dzi = 0; 
      }

    


      this->partials_output_layer[i].dc_dai = this->NN_to_train.get_output_layer[i].a 
        - this->my_training_data[this->training_example_ctr - 1].y;
      this->partials_output_layer[i].dai_dzi


      for (int j = 0 ; j < this->NN_to_train.get_third_layer().size(); j++){
        // for all the weights in this neuron 
      this->partials_output_layer[i].dzi_dwi_vec[j] = this-> NN_to_train.get_third_layer[j].a;


    }  
      // this is always just like this ... never changes
      this->partials_output_layer[i].dzi = 1; 


      // populate the dzi_daj vec 
      for (int j = 0 ; j < this->network_to_train.get_third_layer().size() ; j++){
        this->partials_output_layer[i].dzi_daj_nminus1_vec.push_back(this->network_to_train.get_output_layer[i].weights[j]);
      }


    }
}




void NN_training::run_training_next_example(){

}

void NN_training::run_all_training(){
  do {
    NN_training::run_training_next_example();
  } while (this->training_example_ctr < my_training_data.get_num_training_examples());
}
