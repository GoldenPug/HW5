/*
   Box.cpp
   By:Jared Maltos
   Created: 11/18/2019
   CS 202: Homework 05
   Purpose: .cpp file for Box
   Details: Put Box.hpp, Box.cpp, and boxtest3.cpp into a project to work
*/

#include "box.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <ostream>

using std::size_t;
using std::string;
using std::ostream;
using std::unique_ptr;

using std::make_unique;

size_t Box::_howMany = 0;

//returns string of type
string Box::type() const {
	switch (_pattern) {
	case 1:
		return "Filled";
		break;
	case 2:
		return "Hollow";
		break;
	case 3:
		return "Checkered";
		break;
	default:
		return "Filled";
	}
}

//prints box to ostream
void Box::print(ostream& stream) const {
	for (int row = 0; row <= _height - 1; row++) {
		for (int col = 0; col <= _width - 1; col++) {
			if (_pattern == CHECKERED) {

				//Checkered
				if (row % 2 != 0 && col % 2 != 0) {

					stream << "x";
				}
				else if (row % 2 == 0 && col % 2 == 0) {

					stream << "x";
				}
				else {

					stream << " ";
				}
			}
			else if ((_pattern == FILLED            //Filled & Hollow
				|| (row == 0 || row == _height - 1)
				|| (col == 0 || col == _width - 1))) {

				stream << "x";
			}
			else {

				stream << " ";
			}
		}
		stream << '\n';
	}
}

//factory function
unique_ptr<Box> boxFactory(char c, int w, int h) {
	switch (c) {
	case 'c':
		return make_unique<CheckeredBox>(w, h);
	case 'f':
		return make_unique<FilledBox>(w, h);
	case 'h':
		return make_unique<HollowBox>(w, h);
	default:
		return nullptr;
	}
}

//overload to insert into ostream
ostream& operator<<(ostream& os, const Box& box) {
	box.print(os);
	return os;
}
//end of file