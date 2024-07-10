#include "data.hpp"





TEST_DATA::TEST_DATA(int dim, std::string equation, int num_data_points, float correctness, bool training = false)
: this->num_data_points(num_data_points), this->dim(dim), this->equation(equation), this->correctness(correctness) , this->training(training)
{




}


struct coord{
	
	std::map<int, int> coord_map;

};


class TEST_DATA{
	std::vector<coord> test_data;

	public:
		TEST_DATA(int dim, std::string equation, int num_data_points);
};
