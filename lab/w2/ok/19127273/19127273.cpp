// 19127273.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include "iostream"
#include <sstream>
#include <cstring>
#include <ctime>
#include "windows.h"
using namespace std;
class Random {
public:
	Random() {
		srand(time(NULL));
	}
	int next() {
		int result = rand();
		return result;
	}
	int next(int n) {
		int result = rand() % n;
		return result;
	}
	int next(int a, int b) {
		int result = rand() % (b - a + 1) + a;
		return result;
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
	NameGenerator next() {
		Random rng;

		string first[] = { "nguyen","huynh","bui","hoang","doan","trinh" };
		setfirst(first[rng.next(sizeof(first) / sizeof(string) - 1)]);

		string middle[] = {"duong","kim","huu","my","quynh" };
		setmiddle(middle[rng.next(sizeof(middle) / sizeof(string) - 1)]);

		string last[] = { "thanh","linh","lien","phuong","thu","phat" };
		setlast(last[rng.next(sizeof(last) / sizeof(string) - 1)]);

		NameGenerator name(firstName(), middleName(), lastName());

		return name;
	}
};

int main()
{
	Random rng1;
	int n=rng1.next(10, 20);
	NameGenerator a;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ".";
		cout << a.next().toString();
		Sleep(1000);
	}
    return 0;
}

