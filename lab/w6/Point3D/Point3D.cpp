// Point3D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <regex>
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
using namespace std;
class Point2D {
private:
	int _x;
	int _y;
public:
	Point2D(){}
	int x() const { return _x; }
	int y() const { return _y; }
	void setX(int value)  { _x = value; }
	void setY(int value) { _y = value; }
public:
	Point2D(int x, int y) {
		_x = x;
		_y = y;
	}
	Point2D(const Point2D &p) {
		this->_x = p._x;
		this->_y = p._y;
	}
public:
	string toString() {
		stringstream out;
		out << "x: " << _x << ", y= " << _y << endl;
		return out.str();
	}
	~Point2D(){}
};
class Point3D :public Point2D {
private:
	int _z;
public:
	Point3D(){}
	int z() const { return _z; }
	void setZ(int value) { _z = value; }
	Point3D(int x,int y,int z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	string toString() {
		stringstream out;
		out << "(" << x() << "," << y() << "," << z() << ")";
		return out.str();
	}
	~Point3D(){}
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
class Tokenizer
{
public:
	static vector<string> split(string haystack, string separator, bool removeEmptyEntries = true)
	{
		vector<string> result;

		int startPos = 0;
		size_t foundPos;

		while (1) {
			foundPos = haystack.find(separator, startPos);

			if (foundPos != string::npos) {
				string token = haystack.substr(startPos, foundPos - startPos);
				result.push_back(token);

				startPos = foundPos + separator.length();
			}
			else {
				string token = haystack.substr(startPos, haystack.length() - startPos);
				result.push_back(token);

				break;
			}
		}
		return result;
	}
};
class PointToStringUIConverter {
public:
	string convert(const Point3D &p) {
		stringstream builder;
		builder << "(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
		string result = builder.str();
		return result;
	}
	bool isValidFormat(string point3d) {
		const regex DigitsPattern("\\b\\d+\,\\d+\,\\d+\\b");
		bool result = regex_match(point3d, DigitsPattern);
		return result;
	}
	Point3D convertBack(string point3d) {
		Point3D result;
		vector<string>token = Tokenizer::split(point3d, ",");
		if (isValidFormat(point3d)) {
			result.setX(stoi(token[0]));
			result.setY(stoi(token[1]));
			result.setZ(stoi(token[2]));
		}
		return result;
	}
};
vector<Point3D> input() {
	Random rng;
	int n = rng.next(3, 7);
	cout << "n=" << n << endl;
	vector<Point3D> point3d;
	Point3D natural(0, 0, 0);
	PointToStringUIConverter converter;
	for (int i = 0; i < n; i++) {
		string buffer;
		cout << "Enter point " << i + 1 << ": ";
		getline(cin, buffer);
		while (converter.isValidFormat(buffer)==0) {
			cout << "Please enter again: ";
			getline(cin, buffer);
		}
		point3d.push_back(converter.convertBack(buffer));
	}
	return point3d;
}
int main()
{
	vector<Point3D> p;
	p = input();
	for (int i = 0; i < p.size(); i++) {
		cout << p[i].toString() << endl;
	}
	ofstream ofs;
	ofs.open("point3d.txt", ios::out);
	for (int i = 0; i < p.size(); i++) {
		ofs << p[i].toString() << endl;
	}
	ofs.close();
    return 0;
}

