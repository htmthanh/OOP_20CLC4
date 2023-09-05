#pragma once
#include <fstream>
#include <sstream>
#include <cstring>
#include <regex>
#include <vector>
#include <iomanip>
#include "math.h"
#include "Date.h"
#include "FakeAddress.h"
#include <iostream>
using namespace std;

class Student
{
private:
	int _ID;
	string _name;
	float _gpa;
	string _tel;
	string _email;
	Date _dob;
	Address _address;

public:
	Student(){}
	Student(const Student &f) {
		this->_ID = f._ID;
		this->_name = f._name;
		this->_gpa = f._gpa;
		this->_tel = f._tel;
		this->_email = f._email;
		this->_dob = f._dob;
		this->_address = f._address;
	}
	Student(int, string, float, string, string, Date, Address);
	int id() const { return _ID; }
	string name() const { return _name; }
	float gpa() const { return _gpa; }
	string tel() const { return _tel; }
	string email() const  { return _email; }
	Date dob() const { return _dob; }
	Address address() const { return _address; }
	void setID(int value) {
		_ID = value;
	}
	void setName(string name) {
		_name = name;
	}
	void setGPA(float gpa) {
		_gpa = gpa;
	}
	void setTel(string tel) {
		_tel = tel;
	}
	void setEmail(string email) {
		_email = email;
	}
	void setDOB(Date dob) {
		_dob = dob;
	}
	void setAdd(Address address) {
		_address = address;
	}
	string toString() {
		stringstream builder;
		builder << "Student: " << id() << " - " << name() << endl;
		builder << "\tGPA=" << gpa() << ", Telephone=" << tel() << endl;
		builder << "\tDOB=" << dob().toString() << endl;
		builder << "\tEmail=" << email() << endl;
		builder << "\tAdresss=" << address().printf();
		string result = builder.str();
		return result;
	}
public:
	static float caculateAverageGPA(vector<Student>);
	static string greaterThanAverageUIConverter(vector<Student>);
};

