



/*
 *
 *
 *                       NEURAL NET:
 *           this object is a standalone neural net
 *
 *
 *
 * */




class neural_net{
  // metadata about the network 
  bool loaded_from_folder;
  std::string network_folder_name;

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


  //network functions
  allocate_gpu_memory_for_network();

  load_network_from_folder();
  
  initialize_new_network();
  he_initialization_for_weights();



  public:
  
  // run the network on an example
  // return true if the network things the coordinate belongs to the equation
  // return false if the network thinks the coordinate does not belong to the equations
  bool run_network_on_one_example(float& x, float& y);

  // only allowed constructor for this object
  // supply either an existing folder_name and new = false in order to load from a folder
  // supply a new folder_name and new = true to create a new network to be saved to folder_name
  neural_net(std::string& folder_name, bool new);






}; // end class neural_net
