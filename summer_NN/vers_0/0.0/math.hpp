#ifndef MATH_HPP
#define MATH_HPP

#include <vector>



namespace math{

		double dot_product(std::vector vec1, std::vector vec2);
		
		double ReLU(double input);

		double sigmoid(double input);
		


		// y is the programs guess and y_hat is what it should have been
		double cost_function(double y, double y_hat);

}





/*

int math(int x ){

return x;
}


int main(){

int answer = math(5);
}




namespace math_library{

int double_(int x){

return 2 * x ; 
}

}


int main(){

int answer = math_library.double_(5);


}
*/

#endif
