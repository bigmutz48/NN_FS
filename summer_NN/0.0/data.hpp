#ifndef DATA_HPP
#define DATA_HPP


#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "coord.hpp"

/*
 *
 *	DATA:
 *
 *	this template is made to be reusable and create an array of data in any dimension
 *
 *
 *
 *
 *
 *
 * */






class data{
	
	public:

	// metadata
	const bool training;



	// params
	const int dim;
	const std::string equation;
	const int num_data_points;
	const double correctness;


	const std::vector<coord> test_data;

		// CORRECTNESS refers to the percentage of coordinates in the data set that should solve
		// the EQUATION
		DATA(int dim, std::string equation, int num_data_points, double correctness,
		
				/* optional arguments*/
				bool training = false
				
				

				);
};




#endif
