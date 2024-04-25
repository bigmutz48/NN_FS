#include <iostream>
#include <fstream>
#include <vector>


int main(){
  std::vector<double> MyVector = {3.0 , 2.0 , 1.0};

  std::ofstream file("savefile.txt");

  for (int i =0 ; i < MyVector.size() ; ++i){
    file << MyVector[i] << " ";
  }
return 0;
}
