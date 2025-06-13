


neural_net::neural_net(std::string& folder_name, bool new){
  
 
  this->loaded_from_folder = new;
  this->network_folder_name = folder_name;


  if(new){
    

  };


  int qty_training_examples;
  std::string training_equation;
  
  int qty_input_neurons;
  int qty_neurons_per_hidden_layer;
  int qty_hidden_layers;
  int qty_output_neurons;
  


  // network itself

  float* input_neuron_array;
  float** hidden_layer_neurons_matrix;
  float* output_neuron_array;

  float*** hidden_layer_weights_array_of_matrices;
  float** output_layer_weights_matrix;

  float** hidden_layer_biases_matrix;
  float* output_layer_biases_array;


}; // end neural_net constructor
