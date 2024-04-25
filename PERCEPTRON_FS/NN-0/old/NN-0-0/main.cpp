#include <iostream>
#include <vector>

// basic neural network from scratch

class perceptron{
  public:
    // create each layer with a function
    void make_InputLayer(int qty) {
    std::vector<double>* inputPtr = new std::vector<double>(qty);
    return (inputPtr);
    }

    void make_FirstLayer(int qty) {
      std::vector<double>* FirstLayerPtr = new std::vector<double>(qty);
      return (FirstLayerPtr);
    }
    void make_SecondLayer(int qty){
      std::vector<double>* SecondLayerPtr = new std::vector<double>(qty);
      return (SecondLayerPtr);
    }
    void make_OutputLayer(int qty){
      std::vector<double>* OutputLayerPtr = new std::vector<double>(qty);
      return (OutputLayerPtr)
    }
}


int main () {
  return 0;
}
