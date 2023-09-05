// Point.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;
class Point {
private:
	int _x;
	int _y;
public:
	int x() { return _x; }
	int y() { return _y; }
	void setX(int value) { _x = value; }
	void setY(int value) { _y = value; }
public:
	Point(int x, int y) {
		_x = x;
		_y = y;
	}
public:
	string toString() {
		stringstream out;
		out << "x: " << _x << ", y= " << _y << endl;
		return out.str();
	}
};

int main()
{
	Point p1(1, 2);
	Point p2(2, 3);
	cout << p1.toString() << endl;
	cout << p2.toString() << endl;
    return 0;
}

