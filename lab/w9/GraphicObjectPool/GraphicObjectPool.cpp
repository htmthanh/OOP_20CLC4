// GraphicObjectPool.cpp : Defines the entry point for the console application.
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
#include <memory>
#include <map>
#define PI 3.14
using namespace std;

class Shape {
public:
	virtual float perimeter() = 0;
	virtual float area() = 0;
	virtual string toString() = 0;
	virtual void parse(string) = 0;
	virtual string magicWord() = 0;
	virtual shared_ptr<Shape> clone() = 0;
	//virtual void Read(ifstream &ifs) = 0;
};

class Rectangle :virtual public Shape {
private:
	float _width;
	float _height;
	
public:
	
	string magicWord() { return "Rectangle"; }
	shared_ptr<Shape> clone() { return make_shared<Rectangle>(); }
	Rectangle(){}
	Rectangle(float width,float height){
		_height = height;
		_width = width;
	}
	
	float width() { return _width; }
	float height() { return _height; }
	
	void setwidth(float width) { _width = width; }
	void setheight(float height) { _height = height; }
	
	void parse(string rec) {
		int lastIndex = rec.find(',');
		int firstIndex = rec.find_first_of('=');
		string widthString = rec.substr(firstIndex + 1, lastIndex);
		int secondIndex = rec.find_last_of('=');
		string heightString = rec.substr(secondIndex + 1, rec.size() - secondIndex - 1);
		_width = stof(widthString);
		_height = stof(heightString);
		//shared_ptr<Shape> res = make_shared<Rectangle>(stof(widthString), stof(heightString));
		//return res;

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
		builder << " Width=" << width() << ", Height=" << height() << " => Area=" << area() << ", Perimeter=" << perimeter();

		string result = builder.str();
		return result;
	}
};

class Circle :public Shape {
private:
	float _radius;
	
public:
	Circle(){}
	string magicWord() { return "Circle"; }
	shared_ptr<Shape> clone() { return make_shared<Circle>(); }
	Circle(float radius){
		_radius = radius;
	}
	float radius() { return _radius; }
	void setradius(float radius) { _radius = radius; }

	void parse(string circle) {
		int firstIndex = circle.find_first_of('=');
		string radiusString = circle.substr(firstIndex + 1, circle.size() - firstIndex - 1);
		_radius = stof(radiusString);
		//shared_ptr<Shape> res = make_shared<Circle>(stof(radiusString));
		
		//return res;
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
		
		builder << " Radius=" << radius() << " => Area=" << area() << ", Perimeter=" << perimeter();
		string result = builder.str();
		return result;
	}
};

class Tokenizer{
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
	Triangle(){}
	string magicWord() { return "Triangle"; }
	shared_ptr<Shape> clone() { return make_shared<Triangle>(); }
	Triangle(float a,float b, float c){
		_a = a;
		_b = b;
		_c = c;
	}
	float a() { return _a; }
	float b() { return _b; }
	float c() { return _c; }
	
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
		//shared_ptr<Shape> res = make_shared<Triangle>(stof(aString), stof(bString), stof(cString));
		_a = stof(aString);
		_b = stof(bString);
		_c = stof(cString);
		//return res;
		
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
		
		builder << " A=" << a() << ", B=" << b() << ", C=" << c() << " => Area=" << area() << ", Perimeter=" << perimeter();
		string result = builder.str();
		return result;
	}
};

class ShapeFactory {
private:
	map<string, shared_ptr<Shape>> pool;
private:
	static shared_ptr<ShapeFactory> _instance;
	
	ShapeFactory() {
		//pool.insert({"Rectangle",make_shared<Rectangle>() });
		//pool.insert({"Circle",make_shared<Circle>() });
		//pool.insert({"Triangle",make_shared<Triangle>() });
	}
public:
	static shared_ptr<ShapeFactory> instance() {
		if (_instance == NULL) {
			auto temp = new ShapeFactory();
			_instance = make_shared<ShapeFactory>(*temp);
		}
		return _instance;
	}
public:
	shared_ptr<Shape> create(string choice) {
		auto shapes = pool[choice];
		shared_ptr<Shape> result=NULL;
		result = shapes->clone();
		return result;
	}
public:
	void display() {
		for (map<string, shared_ptr<Shape>>::iterator it =pool.begin();
			it != pool.end();
			it++) {
			cout << it->first << it->second->toString() << endl;
		}
	}
	
	void Read(string filename){
		ifstream ifs;
		ifs.open(filename, ios::in);
		
		string buffer;
		shared_ptr<Shape> shape;
		
		pool.clear();
		vector<shared_ptr<Shape>> result;
		while (!ifs.eof()) {
			getline(ifs, buffer);
			if (buffer.find("Rectangle")!=-1) {
				shape = make_shared<Rectangle>();
				
				//shape->parse(buffer);
				
			}
			else if (buffer.find("Circle")!=-1) {
				shape = make_shared<Circle>();
				//shape->parse(buffer);
				
			}
			else if (buffer.find("Triangle")!=-1) {
				shape = make_shared<Triangle>();
				//shape->parse(buffer);
				
			}
			shape->parse(buffer);
			pool.insert({shape->magicWord(),shape});
			//result.push_back(shape);
			cout  <<shape->magicWord()<< " " << pool.at(shape->magicWord())->toString() << endl;
		}
		//cout << pool.size() << endl;
		ifs.close();
		//return result;
	}
	void print(string choice) {
		
		cout << pool[choice] << " " << pool.at(choice)->toString();
		
		
	}
};
shared_ptr<ShapeFactory> ShapeFactory::_instance = NULL;

int main()
{
	auto shapes=ShapeFactory::instance();
	shapes->Read("data.txt");
	return 0;
}


