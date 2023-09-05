#pragma once
#include "Point.h"
#include <string>

class Line {
private:
	Point _start;
	Point _end;
public:
	Point getStart();
	Point getEnd();
	void setStart(Point);
	void setEnd(Point);
public:
	Line();
	Line(Point, Point);
public:
	/// <summary>
	/// Return a string representation of a line
	/// </summary>
	/// <returns>A string in this format ((x1, y1), (x2, y2))</returns>
	string toString();
};