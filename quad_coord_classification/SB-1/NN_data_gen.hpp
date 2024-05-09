#ifndef NN_DATA_GEN_HPP
#define NN_DATA_GEN_HPP
#include <iostream>
#include <vector>

struct coord{
  int x;
  int y;
};

class DataGen{
  public:
    DataGen(int qty);
    
    ~DataGen();
    
    std::vector<coord> TrainingData;

  private:
    // user shouldn't be able to access this 
    std::vector<coord> create_TrainingData(int qty);



    int quadratic(int x);

};

#endif
