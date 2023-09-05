#pragma once
#include "Student.h"
#include <vector>
#include <iostream>
using namespace std;
class StudentDataReader
{
private:
	string _fname;
public:
	StudentDataReader(){}
	StudentDataReader(string fname) {
		_fname = fname;
	}
	vector<Student> read();
};

