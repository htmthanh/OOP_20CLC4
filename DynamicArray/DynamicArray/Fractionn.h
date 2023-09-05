#pragma once
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;

class Fraction {
private: // attributes
	int _num;
	int _denom;
public:
	int num();
	int denom();

	void setNum(int value);
	void setDenom(int value);
public: //constructor
	Fraction();
	Fraction(int num, int denom);
public:
	int gcd(int a, int b);
	Fraction lowest();
	Fraction add(Fraction &a);

public: // to string
	string toString();
	~Fraction();
};