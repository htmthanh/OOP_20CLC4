#include "stdafx.h"
#include "Date.h"
#include <ctime>


Date::Date()
{
	time_t info = time(NULL);
	struct tm newtime;
	localtime_s(&newtime,&info);

	m_day = newtime.tm_mday;
	m_month = newtime.tm_mon + 1;
	m_year = newtime.tm_year + 1900;


}


Date::Date(int day, int month, int year)
{
	m_day = day;
	m_month = month;
	m_year = year;
}

string Date::toString()
{
	string date;

	if (m_day < 10)
		date = "0" + to_string(m_day);
	else
		date = to_string(m_day);
	if (m_month < 10)
		date = date + "/0" + to_string(m_month);
	else
		date = date + "/" + to_string(m_month);
	date = date + "/" + to_string(m_year);

	return date;
}

Date Date::parse(string date)
{
	Date res;
	vector<string>token = Tokenizer::split(date, "/");
	res.setDay(stoi(token[0]));
	res.setMonth(stoi(token[1]));
	res.setYear(stoi(token[2]));
	return res;
}

bool Date::tryParse(string date, Date& Date)
{
	if (this->isValid(date) == true)
		Date = *this;

	return this->isValid(date);
}

bool Date::isValid(string date)
{
	this->parse(date);

	if (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11) {
		if (m_day > 30)
			return false;
	}
	else if (m_month == 2) {
		if (this->isLeapYear(m_year) == true) {
			if (m_day > 29)
				return false;
		}
		else if (m_day > 28)
			return false;
	}
	else if (m_day > 31)
		return false;

	return true;
}

bool Date::isLeapYear(int year)
{
	if ((year % 100) % 4 == 0)
		return true;
	return false;
}
