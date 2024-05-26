#ifndef NN_CREATE_TRAINING_DATA_HPP
#define NN_CREATE_TRAINING_DATA_HPP
#include <vector>
#include <iostream>


struct training_example{
double x;
double y = x ** 2;

};

class training_data{
  int num_training_examples;

  std::vector<training_example> my_training_data;


  

  public:
    training_data(int num_training_examples);
    ~training_data();
    void get_training_data();

    void get_num_training_examples() const;
};

#endif
