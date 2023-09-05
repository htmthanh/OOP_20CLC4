#include "Fullname.h"
#include <sstream>

string Fullname::getFirstname() {
	return this->_firstname;
}

string Fullname::getMiddlename() {
	return this->_middlename;
}

string Fullname::getLastname() {
	return this->_lastname;
}

void Fullname::setFirstname(string value) {
	this->_firstname = value;
}

void Fullname::setMiddlename(string value) {
	this->_middlename = value;
}

void Fullname::setLastname(string value) {
	this->_lastname = value;
}

// Derivative property
string Fullname::getFullname() {
	stringstream out;
	out << _firstname << " " << _middlename << " "
		<< _lastname;

	string result = out.str();
	return result;
}

Fullname::Fullname() {
	// Do nothing
}

Fullname::Fullname(string first, string middle, string last) {
	this->_firstname = first;
	this->_middlename = middle;
	this->_lastname = last;
}

string Fullname::toString() {
	stringstream out;
	out << _firstname << " " << _middlename << " "
		<< _lastname;

	string result = out.str();
	return result;
}