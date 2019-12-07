/*
   Box.hpp
   By:Jared Maltos
   Created: 11/18/2019
   CS 202: Homework 05
   Purpose: .hpp file for Box
   Details: Put Box.hpp, Box.cpp, and boxtest3.cpp into a project to work
*/


#ifndef BOX_HPP_
#define BOX_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <ostream>

using std::size_t;
using std::string;
using std::ostream;
using std::unique_ptr;

class Box {
public:

	//In order to add new type of box, you add the type below in ENUM
	//You add new type to type() and getType functions in box.cpp
	//You add additional logic to print() function

	enum Pattern {
		FILLED = 1,
		HOLLOW = 2,
		CHECKERED = 3
	};

	static size_t _howMany;

	//default constructor
	Box()
		: _height(1), _width(1), _pattern(FILLED) {
		_howMany++;
	}

	//data constructor
	Box(const size_t& width, const size_t& height)
		: _height(height), _width(width), _pattern(FILLED) {
		_howMany++;
	}

	//data and type constructor
	Box(const size_t& width, const size_t& height, const Pattern PATTERN)
		: _height(height), _width(width), _pattern(PATTERN) {
		_howMany++;
	}

	//copy constructor
	Box(const Box& box)
		: _height(box.getHeight()), _width(box.getWidth()), _pattern(box.getType()) {
		_howMany++;
	}

	//destructor
	virtual ~Box() { _howMany--; }

	//accessors
	int getHeight() const { return _height; }
	int getWidth() const { return _width; }
	static size_t howMany() { return _howMany; }
	Pattern getType() const { return _pattern; }


	//mutators
	void setHeight(const size_t& height) { _height = height; }
	void setWidth(const size_t& width) { _width = width; }

	//returns string of type
	string type() const;

	//prints the box to the ostream
	virtual void print(ostream& stream) const;

	//overload to insert into ostream
	friend ostream& operator<<(ostream& os, const Box& box);

protected:
	size_t _height;
	size_t _width;
	Pattern _pattern;

};

class FilledBox : public Box {
public:
	FilledBox() : Box() { _howMany++; }
	FilledBox(const size_t& width, const size_t& height)
		: Box() {
		_height = height;
		_width = width;
		_pattern = FILLED;
		_howMany++;
	}
	~FilledBox() { _howMany--; }

	int getWidth() const { return _width; }
	int getHeight() const { return _height; }
	string type() const { return "Filled"; }

	void setWidth(const size_t& width) {
		_width = width;
	}
	void setHeight(const size_t& height) {
		_height = height;
	}

	//overload to insert into ostream
	friend ostream& operator<<(ostream& os, const Box& box);

	void print(ostream& stream) const { return Box::print(stream); }
};

class HollowBox : public Box {
public:
	HollowBox() : Box() { _howMany++; }
	HollowBox(const size_t& width, const size_t& height)
		: Box() {
		_height = height;
		_width = width;
		_pattern = HOLLOW;
		_howMany++;
	}
	~HollowBox() { _howMany--; }

	int getWidth() const { return _width; }
	int getHeight() const { return _height; }
	string type() const { return "Hollow"; }

	void setWidth(const size_t& width) {
		_width = width;
	}
	void setHeight(const size_t& height) {
		_height = height;
	}

	//overload to insert into ostream
	friend ostream& operator<<(ostream& os, const Box& box);

	void print(ostream& stream) const { return Box::print(stream); }
};

class CheckeredBox : public Box {
public:
	CheckeredBox() : Box() { _howMany++; }
	CheckeredBox(const size_t& width, const size_t& height)
		: Box() {
		_height = height;
		_width = width;
		_pattern = CHECKERED;
		_howMany++;
	}
	~CheckeredBox() { _howMany--; }

	int getWidth() const { return _width; }
	int getHeight() const { return _height; }
	string type() const { return "Checkered"; }

	void setWidth(const size_t& width) {
		_width = width;
	}
	void setHeight(const size_t& height) {
		_height = height;
	}

	//overload to insert into ostream
	friend ostream& operator<<(ostream& os, const Box& box);

	void print(ostream& stream) const { return Box::print(stream); }
};

//factory function
unique_ptr<Box> boxFactory(char c, int w, int h);
#endif
//end of file