#include "math.hpp"

#include <iostream>

namespace math{



float dot_product(std::vector vec1, std::vector vec2){
	
	float val = 0.0;

	if(vec1.size() != vec2.size()){
	std::cerr << "math.dot_product: vectors not the same size for dot product multiplication" << std::endl;
	return;
	} else {
	for (int i = 0 ; i < vec1.size() ; i++){
	val += vec1[i] * vec2[i];
	}

	}



}



float sigmoid(float input){

}

float ReLU(float input){
	float val = 0.0;

	if (input > 0){
	val = input;
	}

	return val;
}



}



