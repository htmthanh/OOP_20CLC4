// DynamicArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include "Fractionn.h"
#include "RandomInterger.h"
using namespace std;



template <class T>

class DynamicArray {
private:
	const int MAX = 128;
	const int STEP = 50;
private:
	T *_a;
	int _maxSize = MAX;
	int _curSize;
public:
	//DynamicArray(){}
	DynamicArray() {
		_a = new T[MAX];
		_maxSize = MAX;
		_curSize = 0;
	}
	int size() {
		return _curSize;
	}
	T& operator[](int index) {
		return _a[index];
	}
	~DynamicArray() {
		delete[] _a;
	}
};

class NameGenerator {
private:
	string _firstName;
	string _middleName;
	string _lastName;
public:
	NameGenerator() {
		_firstName = _middleName = _lastName = { "" };
	}
	NameGenerator(string firstName, string middleName, string lastName) {
		_firstName = firstName;
		_middleName = middleName;
		_lastName = lastName;
	}
	string firstName() { return _firstName; }
	string middleName() { return _middleName; }
	string lastName() { return _lastName; }
	void setfirst(string first) { _firstName = first; }
	void setmiddle(string middle) { _middleName = middle; }
	void setlast(string last) { _lastName = last; }
	string toString() {
		stringstream out;
		out << _firstName << " " << _middleName << " " << _lastName << endl;
		return out.str();
	}
};

class RandomName :public NameGenerator {
public:
	NameGenerator next() {
		RandomInterger rng;
		string first[] = { "nguyen","tran","ho","pham","le","ly","huynh","hoang","phan","vu","vo","dang","bui","do","doan" };
		setfirst(first[rng.next(sizeof(first) / sizeof(string) - 1)]);

		string middle[] = { "van","thi","hoai","tien","kim","thuy","thanh","huu","my","quang" };
		setmiddle(middle[rng.next(sizeof(middle) / sizeof(string) - 1)]);

		string last[] = { "anh","binh","cuong","duong","huong","hanh","ha","linh","kien","khang","truc","han","vy","thu","phong" };
		setlast(last[rng.next(sizeof(last) / sizeof(string) - 1)]);

		NameGenerator name(firstName(), middleName(), lastName());

		return name;
	}
};

int main()
{
	DynamicArray<Fraction> a;
	RandomInterger rng;
	int n = rng.next(1, 10);
	//cout << a.size();
	cout << "Size : " << n << endl;
	cout << "----FRACTION----" << endl;
	Fraction sum;
	sum.setNum(0); 
	sum.setDenom(1);
	for (int i = 0; i < n; i++) {
		a[i].setNum(rng.next(1, 10));
		a[i].setDenom(rng.next(1, 10));
		sum=sum.add(a[i]);
		cout << i + 1 << ". ";
		cout << a[i].toString();
		Sleep(1000);
	}
	cout << "Sum : " << sum.toString();
	Sleep(1000);
	cout << "----NAME----" << endl;
	DynamicArray<RandomName> b;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". ";
		cout << b[i].next().toString();
		Sleep(1000);
	}
	cin.get();
	return 0;
}

