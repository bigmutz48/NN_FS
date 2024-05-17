#ifndef NN_INIT_HPP
#define NN_INIT_HPP

// This class is only for initializng a blank neural net with no parameters

struct neuron{
  int layer_index;
  double activation_val;
  double bias_val;
  double raw_activation_val;
  std::vector<double>* weights_vector = nullptr;
  
}

struct NN{
  int num_training_examples;
  std::vector<double>* input_layer = nullptr;
  std::vector<neuron>* first_hidden_layer_neurons = nullptr;
  std::vector<neuron>* second_hiddenlayer_neurons = nullptr;
  std::vector<neuron>* third_hidden_layer_neurons = nullptr;
  std::vector<neuron>* output_layer_neurons = nullptr
}


class NN_INIT{
  // initialization parameters
    int qty_input;
    int qty_first;
    int qty_second;
    int qty_third;
    int qty_output;




  // functions to initialize a new network
    void initialize_weights(NN network_to_init);
    void initialize_biases(NN network_to_init);




  //create the NN object
    NN my_NN;

  // set the object up
  initialize_weights(my_NN);
  initialize_biases(my_NN);
  



  public:
    // user should only be able to do a few things with this class

    // constructor for this class 
    NN_INIT(
        int qty_input,
        int qty_first,
        int qty_second,
        int qty_third,
        int qty_output
        );
    ~NN_INIT();
    
    NN get_NN();



};

#endif
