// 19127273_W1b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <sstream>
#include <cstring>
#include <ctime>
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
		int result=rand() % (b - a + 1) + a;
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
	/*string shortened_name() {
		string name = _firstName.substr(0, 1) + _middleName.substr(0, 1) + _lastName;
		return name;
	}*/
	string toString() {
		stringstream out;
		out << _firstName << " " << _middleName << " " << _lastName << endl;
		return out.str();
	}
	NameGenerator next() {
		Random rng;

		string first[] = { "nguyen","tran","ho","pham","le","ly","huynh","hoang","phan","vu","vo","dang","bui","do","doan" };
		setfirst(first[rng.next(sizeof(first) / sizeof(string) - 1)]);

		string middle[] = { "van","thi","hoai","tien","kim","thuy","thanh","huu","my","quang" };
		setmiddle(middle[rng.next(sizeof(middle) / sizeof(string) - 1)]);

		string last[] = { "anh","binh","cuong","duong","huong","hanh","ha","linh","kien","khang","truc","han","vy","thu","phong" };
		setlast(last[rng.next(sizeof(last) / sizeof(string) - 1)]);

		NameGenerator name(firstName(), middleName(), lastName());

		return name;
	}
	/*NameGenerator next() {
		Random rng;
		string first[] = { "le","huynh","tran","nguyen","hoang","doan" };
		string middle[] = { "my","quynh","bao","hong","tu","anh" };
		string last[] = { "thanh","lien","linh","hau","phat","quynh" };
		_firstName = first[rng.next(sizeof(first) / sizeof(string) - 1)];
		_middleName = middle[rng.next(sizeof(middle) / sizeof(string) - 1)];
		_lastName = last[rng.next(sizeof(last) / sizeof(string) - 1)];
		NameGenerator name(_firstName, _middleName, _lastName);
		return name;
	}*/

};
/*class RandomName :public NameGenerator {
public:
	NameGenerator next() {
		Random rng;

		string first[] = { "nguyen","tran","ho","pham","le","ly","huynh","hoang","phan","vu","vo","dang","bui","do","doan" };
		setfirst( first[rng.next(sizeof(first) / sizeof(string) - 1)]);

		string middle[] = { "van","thi","hoai","tien","kim","thuy","thanh","huu","my","quang" };
		setmiddle(middle[rng.next(sizeof(middle) / sizeof(string) - 1)]);

		string last[] = { "anh","binh","cuong","duong","huong","hanh","ha","linh","kien","khang","truc","han","vy","thu","phong" };
		setlast(last[rng.next(sizeof(last) / sizeof(string) - 1)]);

		NameGenerator name(firstName(), middleName(), lastName());

		return name;
	}
};*/
int main()
{
	/*RandomName a;
	for (int i = 0; i < 15; i++) {
		cout << i + 1 << ".";
		cout << a.next().toString();
	}*/
	Random rng;
	int n = rng.next(10, 20);
	cout << " n = " << n << endl;
	NameGenerator *a;
	a = new NameGenerator[n];
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ".";
		cout << a[i].next().toString();
	}
	delete[]a;
    return 0;
}

