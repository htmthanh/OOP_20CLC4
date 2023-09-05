// FractionSerializationDeserialization.cpp : Defines the entry point for the console application.
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
	int num() { return _num; }
	int denom() { return _denom; }

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
	Fraction add(Fraction a) {
		Fraction result;
		result._num = _num*a.denom() + a.num()*_denom;
		result._denom = _denom*a.denom();
		return result;
	}
	string toString() {
		stringstream out;
		out << _num <<"/"<< _denom;
		return out.str();
	}
};

class FractionToStringUIConverter :public Fraction {
public:
	string convert(const Fraction&f) {
		
	}
	Fraction converBack(string fraction) {
		int firstIndex = fraction.find_first_of("/");
		string numString = fraction.substr(0, firstIndex);
		string denomString = fraction.substr(firstIndex + 1, fraction.size() - firstIndex - 1);
		Fraction result(0,1);
		if (isValidFormat(fraction)) {
			result.setNum(stoi(numString));
			result.setDenom(stoi(denomString));
		}
		return result;

	}
	bool tryConvertBack(string fraction) {
		bool result = true;
		int firstIndex = fraction.find_first_of("/");
		string numString = fraction.substr(0, firstIndex);
		string denomString = fraction.substr(firstIndex + 1, fraction.size() - firstIndex - 1);
		if (isValidFormat(fraction)) {
			Fraction a;
			a.setNum(stoi(numString));
			a.setDenom(stoi(denomString));
		}
		else
			result = false;
		return result;
	}
	bool isValidFormat(string fraction) {
		const regex DigitsPattern("\\b\\d+\/\\d+\\b");
		bool result = regex_match(fraction, DigitsPattern);
		return result;
	}
};

class FractionDataReader {
private:
	string _connectionString;
public:
	FractionDataReader(string connectionString) {
		_connectionString = connectionString;
	}
	vector<Fraction> GetAll() {
		ifstream connectionString;
		connectionString.open(_connectionString, ios::in);
		vector <Fraction> f;
		while (!connectionString.eof()) {
			string buffer;
			getline(connectionString, buffer);
			FractionToStringUIConverter converter;
			// nếu là phân số thì add vào mảng 
			if (converter.tryConvertBack(buffer) == 1)
			{
				Fraction p = converter.converBack(buffer);
				f.push_back(p);
			}
		}
		connectionString.close();
		return f;
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
	FractionDataReader reader("data.txt");
	vector<Fraction> list = reader.GetAll();
	FractionToLowestTermConverted lowest;
	cout << "Fractions have been read from file: ";
	for (int i = 0; i < list.size(); i++) {
		cout << lowest.convert(list[i]);
		if (i == list.size() - 1) cout << endl;
		else cout << ", ";
	}
	RandomFractionGenerator randomF;
	Fraction p1, p2;
	p1 = randomF.next(1, 5);
	p2 = randomF.next(1, 5);
	list.push_back(p1);
	list.push_back(p2);
	cout << "Generate 2 fractions in lowest term: " << lowest.convert(p1) << ", " << lowest.convert(p2) << endl;
	Fraction sum(0, 1);
	for (int i = 0; i < list.size(); i++) {
		sum = sum.add(list[i]);
		//cout << list[i].toString() << endl;
	}
	cout <<"Sum: "<< lowest.convert(sum) << endl;
	// ghi thêm 2 phân số vừa được thêm vào
	ofstream ofs;
	ofs.open("data.txt", ios::out);
	for (int i = 0; i < list.size(); i++) {
		ofs << list[i].toString() << endl;
	}
	ofs.close();
	//cin.get();
    return 0;
}

