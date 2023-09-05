// GraphicAreaPerimeter.cpp : Defines the entry point for the console application.
//

// GraphicAreaPerimeter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <regex>
#include <vector>
#include <iomanip>
#include "math.h"
#include <iostream>
#define PI 3.14
using namespace std;
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
class RandomFloat {
public:
	float float_rand(float min, float max) {
		float scale = rand() / (float)RAND_MAX;
		float result = min + scale*(max - min);
		float res = roundf(result * 100) / 100;
		return res;
	}
};
class Shape {
public:
	virtual float perimeter() = 0;
	virtual float area() = 0;
	virtual string toString() = 0;
	//virtual void setwidth() = 0;
	//virtual void setheight() = 0;
	//virtual void setradius() = 0;
	//virtual void seta() = 0;
	//virtual void setb() = 0;
	//virtual void setc() = 0;
	virtual void parse(string )=0;
};
class Rectangle :public Shape {
private:
	float _width;
	float _height;
public:

	float width() { return _width; }
	float height() { return _height; }
	//void setwidth(float width) { _width = width; }
	//void setheight(float height) { _height = height; }
	void set() {
		RandomFloat rng;
		float width = rng.float_rand(1, 10);
		float height = rng.float_rand(1, 10);
		_width = width;
		_height = height;
	}
	void parse(string rec) {
		int lastIndex = rec.find(',');
		int firstIndex = rec.find_first_of('=');
		string widthString = rec.substr(firstIndex + 1, lastIndex);
		int secondIndex = rec.find_last_of('=');
		string heightString = rec.substr(secondIndex + 1, rec.size() - secondIndex - 1);
		_width = stof(widthString);
		_height = stof(heightString);
	}
	float perimeter() {
		float result = (width() + height()) * 2;
		return result;
	}
	float area() {
		float result = width()*height();
		return result;
	}
	string toString() {
		stringstream builder;
		//builder << fixed;
		builder << "Rectangle: Width=" << width() << ", Height=" << height() << " => Area=" << area() << ", Perimeter=" << perimeter();

		string result = builder.str();
		return result;
	}
};
class Circle :public Shape {
private:
	float _radius;
public:
	float radius() { return _radius; }
	//void setradius(float radius) { _radius = radius; }
	
	void parse(string circle) {
		int firstIndex = circle.find_first_of('=');
		string radiusString = circle.substr(firstIndex + 1, circle.size() - firstIndex - 1);
		_radius = stof(radiusString);
	}
	float perimeter() {
		float result = 2 * PI*radius();
		return result;
	}
	float area() {
		float result = PI*radius()*radius();
		return result;
	}
	string toString() {
		stringstream builder;
		//builder << fixed;
		builder << "Circle: Radius=" << radius() << " => Area=" << area() << ", Perimeter=" << perimeter();
		string result = builder.str();
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
class Triangle :public Shape {
private:
	float _a;
	float _b;
	float _c;
public:
	float a() { return _a; }
	float b() { return _b; }
	float c() { return _c; }
	//void seta(float a) { _a = a; }
	//void setb(float b) { _b = b; }
	//void setc(float c) { _c = c; }
	bool check(float a, float b, float c) {
		if (a < b + c && b < a + c && c < a + b) {
			return true;
		}
		return false;
	}

	void parse(string tri) {
		vector<string>token = Tokenizer::split(tri, ",");
		int index1 = token[0].find_first_of('=');
		string aString = token[0].substr(index1 + 1, token[0].size() - index1 - 1);
		int index2 = token[1].find_first_of('=');
		string bString = token[1].substr(index2 + 1, token[1].size() - index2 - 1);
		int index3 = token[2].find_first_of('=');
		string cString = token[2].substr(index3 + 1, token[2].size() - index3 - 1);
		_a = stoi(aString);
		_b = stoi(bString);
		_c = stoi(cString);
	}
	float perimeter() {
		float result = a() + b() + c();
		return result;
	}
	float area() {
		float p = perimeter() / 2;
		float result = sqrt(p*(p - a())*(p - b())*(p - c()));
		return result;
	}
	string toString() {
		stringstream builder;
		//builder << fixed;
		builder << "Triangle: A=" << a() << ", B=" << b() << ", C=" << c() << " => Area=" << area() << ", Perimeter=" << perimeter();
		string result = builder.str();
		return result;
	}
};

vector<Shape*> getAll() {
	ifstream ifs;
	ifs.open("data.txt", ios::in);
	string buffer;
	//vector<string> input;
	vector<Shape*> result;
	Shape* shape;
	while (!ifs.eof()) {
		getline(ifs, buffer);
		if (buffer.find("Rectangle")!=-1) {
			shape= new Rectangle();
			shape->parse(buffer);
		}
		else if (buffer.find("Circle")!=-1) {
			shape = new Circle();
			shape->parse(buffer);
		}
		else if (buffer.find("Triangle")!=-1) {
			shape = new Triangle();
			shape->parse(buffer);
		}
		result.push_back(shape);
	}
	ifs.close();
	return result;
}
int main()
{
	
	vector<Shape*> list=getAll();

	for (int i = 0; i < list.size(); i++) {
		cout << list[i]->toString() << endl;
	}
	return 0;
}

