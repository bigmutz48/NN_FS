#include "NN_data_gen.hpp"
#include <vector>
#include <iostream>

DataGen::DataGen(int qty){
  this-> TrainingData = create_TrainingData(qty);
}


int DataGen::quadratic(int x){

  return x ** 2;
}

std::vector<coord> DataGen::create_TrainingData(int qty){
  std::vector<coord> Data(qty);
  for (int i = 0 ; i < qty ; i++){
    Data[i].x = i;
    Data[i].y = quadratic(i);
  }
}
