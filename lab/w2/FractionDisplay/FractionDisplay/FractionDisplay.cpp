// FractionDisplay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
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
	//Fraction(){}
	Fraction() {
		_num = 0;
		_denom = 1;
	}

	Fraction(int num, int denom) {
		_num = num;
		_denom = denom;
	}
	~Fraction() {}
public: // to string
	string toString() {
		stringstream out;
		out << _num << "/" << _denom << endl;;
		return out.str();
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
class RandomFractionGenerator {
private:
	Random _rng;
public:
	Fraction next() {
		Fraction result;
		result.setNum(rand());
		result.setDenom(rand());
		return result;
	}
	Fraction next(int ceiling) {
		Fraction result;
		result.setNum(rand() % ceiling);
		result.setDenom(rand() % ceiling);
		return result;
	}
	
	Fraction next(int left, int right) {
		Fraction result;
		result.setNum(left + rand() % (right + 1 - left));
		result.setDenom(left + rand() % (right + 1 - left));
		return result;
	}
};
class Integer {
public:
	static int gcd(int a, int b) {
		while (a != b) {
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		return a;
	}
};

class FractionToLowestTermConverted:public Integer {
public:
	string convert( Fraction &f) {
		stringstream out;
		int d = gcd(f.num(),f.denom()); 
		int r = f.num() % f.denom(); 
		int temp = f.num() / f.denom(); 
		// lowest
		if (f.num() < f.denom()) {
			int lowNum = f.num() / d;
			int lowDenom = f.denom() / d;
			out << lowNum << "/" << lowDenom;
		}
		// mixed format
		else if (f.num() > f.denom() && r != 0) {
			int d1 = gcd(r, f.denom());
			int lowNum1 = r / d1;
			int lowDenom1 = f.denom() / d1;
			out << temp << " " << lowNum1 << "/" << lowDenom1;
		}
		//full number
		else 
			out << temp;
		return out.str();
	}
};
class FractionToDecimalConverter {
private:
	int _precision;
	bool _isFixed;
public:
	FractionToDecimalConverter(){}
	FractionToDecimalConverter(int pre, bool check) {
		pre = _precision = 1;
		check = _isFixed=true;
	}
public: 
	string convert(Fraction &f) {
		stringstream out;
		double decNum = double(f.num());
		double decDenom = double(f.denom());
		double dec = (decNum) / (decDenom);
		out << fixed << setprecision(2) << dec;
		return out.str();
	}
};
class FractionToPercentageConverter {
private:
	int _precision;
	bool _isFixed;
public:
	FractionToPercentageConverter(){}
	FractionToPercentageConverter(int pre, bool check) {
		pre = _precision = 1;
		check = _isFixed = true;
	}
public:
	string convert(Fraction &f) {
		stringstream out;
		double decNum = double(f.num());
		double decDenom = double(f.denom());
		double dec = (decNum / decDenom)*100;
		out << fixed << setprecision(2) << dec;
		return out.str();
	}
};
int main()
{
	Random rng;
	int n = rng.next(15, 25);
	Fraction *a;
	a = new Fraction[n];
	//cout << n << endl;
	RandomFractionGenerator b;
	FractionToLowestTermConverted c;
	for (int i = 0; i < n; i++) {
		a[i]=b.next(1, 50);
		//cout << a[i].toString(); 
	}
	ofstream writer;
	writer.open("data.txt", ios::out);
	for (int i = 0; i < n; i++) {
		//a[i] = b.next(1, 50);
		writer << a[i].toString();
	}
	writer.close();
	cout << "LOWEST FRACTION: " << endl;
	for (int i = 0; i < n; i++) {
		cout << c.convert(a[i]);
		if (i == n - 1) cout << "." << endl;
		else cout << ", ";
	}
	cout << endl << "FRACTION TO DECIMAL: " << endl;
	FractionToDecimalConverter f;
	for (int i = 0; i < n; i++) {
		cout << f.convert(a[i]);
		if (i != n - 1)cout << ", ";
		else cout << "." << endl;
	}

	cout << endl << "FRACTION TO PERCENTAGE: " << endl;
	FractionToPercentageConverter g;
	for (int i = 0; i < n; i++) {
		cout << g.convert(a[i]) << "%";
		if (i != n - 1)cout << ", ";
		else cout << "." << endl;
	}
	
    return 0;
}

