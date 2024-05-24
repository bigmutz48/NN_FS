#include "my_math.hpp"


double my_math::ReLU(double input){
  if (input <= 0 ){
    return 0;
  } else {
    return input;
  }
}

