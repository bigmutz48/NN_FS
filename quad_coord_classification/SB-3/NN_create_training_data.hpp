#ifndef NN_CREATE_TRAINING_DATA_HPP
#define NN_CREATE_TRAINING_DATA_HPP

class training_data{
  int num_training_examples;
  public:
    training_data();
    ~training_data();
    void get_training_data();

    void get_num_training_examples() const;
};

#endif
