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
	
	virtual void parse(string )=0;
	
	
};

class Rectangle :public Shape {
private:
	float _width;
	float _height;
	static Rectangle* _instance;
	Rectangle(){
		//srand(time(NULL));
	}
public:
	static Rectangle* instance() {
		if (_instance == nullptr) {
			_instance = new Rectangle();
		}
		return _instance;
	}
	float width() { return this->_width; }
	float height() { return this->_height; }
	//void setwidth(float width) { _width = width; }
	//void setheight(float height) { _height = height; }
	//void set(Rectangle rec) {
		
	//}
	//void set() {
	//	RandomFloat rng;
	//	float width = rng.float_rand(1, 10);
	//	float height = rng.float_rand(1, 10);
	//	_width = width;
	//	_height = height;
	//}
	void set(float width, float height) {
		this->_height = height;
		this->_width = width;
	}
	void parse(string rec) {
		int lastIndex = rec.find(',');
		int firstIndex = rec.find_first_of('=');
		string widthString = rec.substr(firstIndex + 1, lastIndex);
		int secondIndex = rec.find_last_of('=');
		string heightString = rec.substr(secondIndex + 1, rec.size() - secondIndex - 1);
		float w = stof(widthString);
		float h = stof(heightString);
		set(w, h);
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
Rectangle* Rectangle::_instance = NULL;
class Circle :public Shape {
private:
	float _radius;
	Circle(){
		//srand(time(NULL));
	}
	static Circle* _instance;
public:
	static Circle* instance() {
		if (_instance == nullptr) {
			_instance = new Circle();
		}
		return _instance;
	}
	float radius() { return this->_radius; }
	//void setradius(float radius) { _radius = radius; }
	void setradius(float radius) {
		this->_radius = radius;
	}
	void parse(string circle) {
		int firstIndex = circle.find_first_of('=');
		string radiusString = circle.substr(firstIndex + 1, circle.size() - firstIndex - 1);
		float ra=stof(radiusString);
		setradius(ra);
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
Circle* Circle::_instance = NULL;
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
	Triangle(){
		
	}
	static Triangle* _instance;
public:
	static Triangle* instance() {
		if (_instance == nullptr) {
			_instance = new Triangle();
		}
		return _instance;
	}
	float a() { return this->_a; }
	float b() { return this->_b; }
	float c() { return this->_c; }
	//void seta(float a) { _a = a; }
	//void setb(float b) { _b = b; }
	//void setc(float c) { _c = c; }
	bool check(float a, float b, float c) {
		if (a < b + c && b < a + c && c < a + b) {
			return true;
		}
		return false;
	}
	void set(float a, float b, float c) {
		this->_a = a;
		this->_b = b;
		this->_c = c;
	}
	void parse(string tri) {
		vector<string>token = Tokenizer::split(tri, ",");
		int index1 = token[0].find_first_of('=');
		string aString = token[0].substr(index1 + 1, token[0].size() - index1 - 1);
		int index2 = token[1].find_first_of('=');
		string bString = token[1].substr(index2 + 1, token[1].size() - index2 - 1);
		int index3 = token[2].find_first_of('=');
		string cString = token[2].substr(index3 + 1, token[2].size() - index3 - 1);
		float a = stoi(aString);
		float b = stoi(bString);
		float c = stoi(cString);
		set(a, b, c);
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
Triangle* Triangle::_instance = NULL;
/*vector<Shape*> getAll() {
	ifstream ifs;
	ifs.open("data.txt", ios::in);
	string buffer;
	//vector<string> input;
	vector<Shape*> result;
	Shape* shape;
	while (!ifs.eof()) {
		getline(ifs, buffer);
		if (buffer.find("Rectangle")!=-1) {
			//shape= new Rectangle();
			//Rectangle* rec = Rectangle::instance();
			shape = Rectangle::instance();
			shape->parse(buffer);
			//shape = rec;
			//result.push_back(shape);
		}
		else if (buffer.find("Circle")!=-1) {
			//shape = new Circle();
			//Circle* cir = Circle::instance();
			shape = Circle::instance();
			shape->parse(buffer);
			//shape = cir;
			//result.push_back(shape);
		}
		else if (buffer.find("Triangle")!=-1) {
			//shape = new Triangle();
			shape = Triangle::instance();
			//Triangle* tri = Triangle::instance();
			shape->parse(buffer);
			//shape = tri;
			//result.push_back(shape);
		}
		result.push_back(shape);
	}
	ifs.close();
	return result;
}*/
//srand(time(NULL));
int main()
{
	srand(time(NULL));
	//vector<Shape*> list=getAll();
	ifstream ifs;
	ifs.open("data.txt", ios::in);
	string buffer;
	//vector<string> input;
	vector<Shape*> result;
	Shape* shape;
	Rectangle* rec = Rectangle::instance();
		Circle* cir = Circle::instance();
		Triangle* tri = Triangle::instance(); 
	while (!ifs.eof()) {
		
		getline(ifs, buffer);
		if (buffer.find("Rectangle") != -1) {
			//shape= new Rectangle();
			//Rectangle* rec = Rectangle::instance();
			//shape = Rectangle::instance();
			rec->parse(buffer);
			shape = rec;
			//result.push_back(shape);
		}
		else if (buffer.find("Circle") != -1) {
			//shape = new Circle();
			//Circle* cir = Circle::instance();
			//shape = Circle::instance();
			cir->parse(buffer);
			shape = cir;
			//result.push_back(shape);
		}
		else if (buffer.find("Triangle") != -1) {
			//shape = new Triangle();
			//shape = Triangle::instance();
			//Triangle* tri = Triangle::instance();
			tri->parse(buffer);
			shape = tri;
			//result.push_back(shape);
		}
		result.push_back(shape);
	}
	ifs.close();
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]->toString() << endl;
	}
	return 0;
}

