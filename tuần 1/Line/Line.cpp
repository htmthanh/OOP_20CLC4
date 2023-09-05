// Line.cpp : Defines the entry point for the console application.
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
	Point ()
	{
		_x = _y = 0;
	}
	Point(const Point &p) {
		_x = p._x;
		_y = p._y;
	}
	Point(int x, int y) {
		_x = x;
		_y = y;
	}
	~Point(){}
	
};
class Line 
{
private:
	Point _p1;
	Point _p2;
public:
	Point p1() { return _p1; }
	Point p2() { return _p2; }
	void setp1(int x, int y) { _p1.setX(x); _p1.setY(y); }
	void setp2(int x, int y) { _p2.setX(x); _p2.setY(y); }
public:
	Line(Point p1,Point p2) {
		_p1 = p1;
		_p2 = p2;
	}

public:
	string toString() {
		
		stringstream out;
		out << "Point a: x=" << _p1.x() << ",y=" << _p1.y() << endl;
		out<< "Point b: x=" << _p2.x() << ",y=" << _p2.y() << endl;
		// tim pt duong thang
		float *a = new float[2];
		a[0] = (_p1.y() - _p2.y()) / (_p1.x() - _p2.x());
		a[1] = (_p2.y()*_p1.x() - _p2.x()*_p1.y()) / (_p1.x() - _p2.x());
		// print out phuong trinh
		out << "=> y = " << a[0] << "*x + " << a[1] << endl;
		return out.str();
	}
};

int main()
{
	Point p1(1, 2);
	Point p2(2, 3);
	Line l1(p1,p2);
	cout << l1.toString() << endl;
    return 0;
}

