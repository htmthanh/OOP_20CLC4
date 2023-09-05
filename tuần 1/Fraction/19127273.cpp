// 19127273.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;
class Fraction {
private: // attributes
	int _num;
	int _denom;
public:
	int num() { return _num; }
	int denom() { return _denom; }

	void setNum(int value) { _num = value; }
	void setDenom(int value) { _denom = value; }
public: //constructor
	Fraction(int num, int denom) {
		_num = num;
		_denom = denom;
	}
public: // to string
	string toString() {
		stringstream out;
		out << "Num: " << _num << ",  Denom: " << _denom << endl;;
		return out.str();
	}
};

int main()
{
	Fraction f1(1, 2);
	Fraction f2(2, 3);
	cout << f1.toString() << endl;
	cout << f2.toString() << endl;
	
    return 0;
}

