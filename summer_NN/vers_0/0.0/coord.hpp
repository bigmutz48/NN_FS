#ifndef COORD_HPP
#define COORD_HPP


#include <string>



// this coordinate template is made to be able to have any amount of dimensions using the map function
struct coord{
	bool valid = false;	
	std::map<std::string, double> coord_map;
	
};

/*
// make the coord
my_coord coord;

// set a value
coord.coord_map["my_age"] = 5.0;


my_coord = [["my_age" , 5.0], [], [], []]

*/


#endif 
