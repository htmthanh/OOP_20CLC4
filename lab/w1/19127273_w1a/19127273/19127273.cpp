// 19127273.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <sstream>
#include <ctime>
#include <iostream>
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
	
	Fraction(){
		_num = 0;
		_denom = 1;
	}
	
	Fraction(int num, int denom) {
		_num = num;
		_denom = denom;
	}
	~Fraction(){}
public: // to string
	string toString() {
		stringstream out;
		out << _num << "/" << _denom << endl;;
		return out.str();
	}
public:
	int gcd(int a, int b) {
		while (a != b) {
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		return a;
	}
public:
	Fraction lowest() {
		int num = _num / gcd(_num, _denom);
		int denom = _denom / gcd(_num, _denom);
		return Fraction(num, denom);
	}
	Fraction add(Fraction a) {
		Fraction result;
		result._num = _num*a.denom() + a.num()*_denom;
		result._denom = _denom*a.denom();
		Fraction finall=result.lowest();
		return finall;
	}
	
};

class Random {
public:
	Random() {
		srand(time(NULL)); // Current time
	}
public:
	int next() {
		int result = rand();
		return result;
	}

	int next(int ceiling) {
		int result = rand() % ceiling;
		return result;
	}
	int next(int min, int max) {
		int result = min + rand() % (max + 1 - min);
		return result;
	}
	
};
int main()
{
	Random n1;
	int n=n1.next(10, 20);
	cout << "n=" << n << endl;

	Fraction *a;
	a = new Fraction[n];
	// random n fractions and save it to array a
	for (int i = 0; i < n; i++) {
		a[i].setNum(n1.next(1, 10));
		a[i].setDenom(n1.next(1, 10));
	}
	
	Fraction result;
	for (int i = 0; i < n; i++) {
		cout <<"Fraction "<<i+1<<" : "<< a[i].toString();
		result = result.add(a[i]);
	}
	
	cout <<"SUM OF THESE FRACTIONS:  "<< result.toString() << endl;

	delete[]a;
	return 0;
}

