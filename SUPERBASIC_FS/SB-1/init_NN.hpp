#ifndef INIT_NN
#define INIT_NN
#include <vector>
// class for user to interact with
class init_NN{
  

// user doesn't need to access very many parts of this class!!
  public:
    int qty_InputLayer;
    int qty_FirstLayer;
    int qty_SecondLayer;
    int qty_ThirdLayer;
    int qty_OutputLayer;


    std::vector<std::vector<std::vector<double>>> WeightsMain;
    std::vector<std::vector<double>> NeuronsMain;


}







#endif
