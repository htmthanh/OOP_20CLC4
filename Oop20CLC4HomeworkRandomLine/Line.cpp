#include "Line.h"
#include <sstream>
using namespace std;

Point Line::getStart() {
	return this->_start;
}
Point Line::getEnd() {
	return this->_end;
}

void Line::setStart(Point value) {
	this->_start = value;
}

void Line::setEnd(Point value) {
	this->_end = value;
}

Line::Line() {
	// Do nothing
}

// Default constructor, parameterized constructor
// Copy constructor _start(a)
Line::Line(Point a, Point b): _start(a), _end(b) {
	/*_start = a;
	_end = b;*/
	// Do nothing
}


string Line::toString() {
	stringstream out;
	out << "(" << _start.toString()
		<< ", " << _end.toString() << ")";

	string result = out.str();
	return result;
}