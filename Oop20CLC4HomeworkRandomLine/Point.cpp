#include "Point.h"

int Point::getX() {
	return this->_x;
}

int Point::getY() {
	return this->_y;
}

void Point::setX(int value) {
	this->_x = value;
}

void Point::setY(int value) {
	this->_y = value;
}

Point::Point() {
	// Do nothing
}

Point::Point(int a, int b) {
	this->_x = a;
	this->_y = b;
}

/// <summary>
/// Return a string representation of a point
/// </summary>
/// <returns>A string int this format (x, y)</returns>
string Point::toString() {
	stringstream out;
	out << "(" << _x << ", " << _y << ")";
 
	string result = out.str();
	return result;
}