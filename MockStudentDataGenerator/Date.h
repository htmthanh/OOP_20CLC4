#pragma once
#include<string>
#include<iostream>
#include <vector>
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
class Date
{
protected:
	int m_day, m_month, m_year;
public:
	Date();
	Date(int, int, int);
	void setDay(int day) {
		m_day = day;
	}
	void setMonth(int month) {
		m_month = month;
	}
	void setYear(int year) {
		m_year = year;
	}
	string toString();
	Date parse(string);
	bool tryParse(string, Date&);
	bool isValid(string);
	bool isLeapYear(int);
};

