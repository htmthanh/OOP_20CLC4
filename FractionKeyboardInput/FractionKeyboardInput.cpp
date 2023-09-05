// FractionKeyboardInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <regex>
#include <vector>
#include <iostream>
using namespace std;
class Fraction {
private: // attributes
	int _num;
	int _denom;
public:
	int num() const { return _num; }
	int denom() const { return _denom; }

	void setNum(int value) { _num = value; }
	void setDenom(int value) { _denom = value; }
public: //constructor
	Fraction() {}
	Fraction(int num, int denom) {
		_num = num;
		_denom = denom;
	}
	Fraction(const Fraction &f) {
		this->_num = f._num;
		this->_denom = f._denom;
	}
public:
	bool operator == (Fraction & rhs)
	{
		if (num()*rhs.denom() == denom()*rhs.num())
			return true;
		else
			return false;

	}
	Fraction add(Fraction a) {
		Fraction result;
		result._num = _num*a.denom() + a.num()*_denom;
		result._denom = _denom*a.denom();
		return result;
	}
	string toString() {
		stringstream out;
		out << _num << "/" << _denom;
		return out.str();
	}
};

class FractionToStringUIConverter :public Fraction {
public:
	string convert(const Fraction&f) {
		stringstream builder;
		builder << f.num() << "/" <<f.denom();
		string result = builder.str();
		return result;
	}
	bool isFractionFormat(string fraction) {
		const regex DigitsPattern("\\b\\d+\/\\d+\\b");
		bool result = regex_match(fraction, DigitsPattern);
		return result;
	}
	bool isMixFormat(string fraction) {
		const regex DigitsPattern("\\b\\d+\ \\b\\d+\/\\d+\\b");
		bool result = regex_match(fraction, DigitsPattern);
		return result;
	}
	bool isFullFormat(string fraction) {
		const regex DigitsPattern("\\b\\d+\\b");
		bool result = regex_match(fraction, DigitsPattern);
		return result;
	}
	Fraction convertBack(string fraction) {
		Fraction result(0, 1);
		int firstSpace = fraction.find_first_of(" ");
		int firstIndex = fraction.find_first_of("/");
		if (isMixFormat(fraction)) {
			string wholeString = fraction.substr(0, firstSpace);
			string numString = fraction.substr(firstSpace + 1, firstIndex);
			string denomString = fraction.substr(firstIndex + 1, fraction.size()
				- firstSpace - 1 - firstIndex - 1);
			int whole = stoi(wholeString);
			int num = stoi(numString);
			int denom = stoi(denomString);
			if (denom != 0) {
				result.setNum((whole*denom) + num);
				result.setDenom(denom);
			}
		}
		else if (isFullFormat(fraction)) {
			int num = stoi(fraction);
			result.setNum(num);
			result.setDenom(1);
		}
		else if (isFractionFormat(fraction)) {
			string numString = fraction.substr(0, firstIndex);
			string denomString = fraction.substr(firstIndex + 1, fraction.size() - firstIndex - 1);
			int num = stoi(numString);
			int denom = stoi(denomString);
			if (denom != 0) {
				result.setNum(stoi(numString));
				result.setDenom(stoi(denomString));
			}
		}
		return result;
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

class FractionToLowestTermConverted :public Integer {
public:
	string convert(Fraction &f) {
		stringstream out;
		int d = gcd(f.num(), f.denom());
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
int main()
{
	int n;
	Random rnd;
	n = rnd.next(5, 10);
	cout << "n="<<n << endl;
	vector<Fraction> f;
	
	
	FractionToStringUIConverter converter;
	Fraction main(0, 1);
	for (int i = 0; i < n; i++) {
		string buffer;
		cout << "Enter fraction " << i + 1 << " : ";
		getline(cin, buffer);
		while (main == converter.convertBack(buffer)) {
			cout << "Please enter again : ";
			getline(cin, buffer);
		}
		f.push_back(converter.convertBack(buffer));
		//cout << f[i].toString() << endl;

	}
	ofstream fout;
	fout.open("data.txt", ios::out);
	for (int i = 0; i < n; i++) {
		fout << f[i].toString() << endl;
	}
	cout << "SAVE SUCCESSFULLY ! " << endl;

	fout.close();
	Fraction sum(0, 1);
	FractionToLowestTermConverted lowestF;
	for (int i = 0; i < n; i++) {
		sum = sum.add(f[i]);
	}
	cout << "SUM (in the LOWEST term): " << lowestF.convert(sum) << endl;
    return 0;
}

