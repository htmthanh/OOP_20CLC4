#pragma once
#include <string>
#include <sstream>
using namespace std;

// Declaration
class Point {
private: // Attributes / Backup fields
	int _x = 0;
	int _y = 0;
public: // Properties
	int getX();
	int getY();
	void setX(int); 
	void setY(int); 
public: // Constructor
	Point();
	Point(int, int);
public: // Methods
	string toString();
};
