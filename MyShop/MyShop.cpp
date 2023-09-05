// MyShop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <regex>
#include <memory>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
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
class Category {
private:
	int _categoryID;
	string _categoryName;
	//vector<shared_ptr<Product>> _products;
public:
	Category() {

	}
	void setID(int ID) {
		_categoryID = ID;
	}
	void setName(string name) {
		_categoryName = name;
	}
	Category parse(string line) {
		Category result;
		vector<string>token = Tokenizer::split(line, ",");
		int separator = token[0].find_first_of('=');
		string catID = token[0].substr(separator + 1, token[0].size()-separator-1);
		result.setID(stoi(catID));
		int separator1 = token[1].find_first_of('=');
		string catName = token[1].substr(separator1 + 1, token[1].size()-separator1-1);
		result.setName(catName);
		return result;
	}
	string toString() {
		stringstream builder;
		builder << "Category: ID=" << _categoryID << ", Name=" << _categoryName;
		string result;
		result = builder.str();
		return result;
	}
};
class Product {
private:
	int _productID;
	string  _productName;
	int _price;
	shared_ptr<Category> _categories;

};
bool ReadCat(string input, vector<Category> &categories) {
	ifstream ifs;
	ifs.open(input, ios::in);
	vector<string> input1;
	while (!ifs.eof()) {
		string buffer;
		getline(ifs, buffer);
		input1.push_back(buffer);
	}
	
	for (int i = 0; i < input1.size(); i++) {
		Category temp;
		Category res;
		res=temp.parse(input1[i]);
		categories.push_back(res);
	}
	for (int i = 0; i < categories.size(); i++) {
		cout << categories[i].toString() << endl;
	}
	ifs.close();
	return true;

}
bool ReadProduct(string input, vector<Product> &products, int categoryID) {
	ifstream ifs;
	ifs.open(input, ios::in);
	while (!ifs.eof()) {

	}
}
int main()
{
	vector<Category> cat;
	ReadCat("category.txt", cat);
	/*ReadCat("category.txt", cat);
	if (ReadCat("category.txt", cat) == 1) {
		for (int i = 0; i < cat.size(); i++) {
			cout<<cat[i].toString() << endl;
		}
	}
	for
	string buffer;
	ifstream ifs;
	vector<string> catero;
	ifs.open("category.txt", ios::in);
	while (!ifs.eof()) {
		getline(ifs, buffer);
		catero.push_back(buffer);
	}
	
	vector<string>token;
	for (int i = 0; i < catero.size(); i++) {
		Tokenizer temp;
		vector<string>splitdone=temp.split(catero[i], ",");
		for (int j = 0; j < splitdone.size(); j++) {
			token.push_back(splitdone[j]);
		}
	}
	for (int i = 0; i < token.size(); i++) {
		cout << token[i] << endl;
	}*/
	int n;
	cout << "Plese choose category: ";
	cin >> n;

    return 0;
}

