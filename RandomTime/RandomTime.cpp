// RandomTime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <sstream>
#include <iomanip>

#include <iostream>
using namespace std;
class RandomIntegerGenerator {
public:
	RandomIntegerGenerator() {
		srand(time(NULL));
	}
public:
	int next() {
		int number = rand();
		return number;
	}

	int next(int left, int right) {
		int number = rand() % (right - left + 1) + left;
		return number;
	}
};
class Time {
private:
	int _hour;
	int _minute;
	int _second;
public:
	int hour() const { return _hour; }
	int minute() const { return _minute; }
	int second() const { return _second; }
	Time() {

	}
	Time(int hour, int minute, int second) {
		_hour = hour;
		_minute = minute;
		_second = second;
	}
public:

	static bool isValidTime(int hour, int min, int sec);
};
bool Time::isValidTime(int hour, int min, int sec) {
	bool result = true;
	if (hour < 0 && hour >24)
		result= false;
	if (min < 0 && min>59)
		result= false;
	if (sec < 0 && sec>59)
		result = false;
	return result;
}
class TimeToStringUIConverter {
public:
	string convert(const Time& date);
};
string TimeToStringUIConverter::convert(const Time &time) {
	stringstream builder;
	builder << setw(2) << setfill('0') << time.hour() << ":";
	builder << setw(2) << setfill('0') << time.minute() << ":";
	builder << setw(2) << setfill('0') << time.second();
	string result = builder.str();
	return result;
}
class RandomTimeGenerator {
private:
	RandomIntegerGenerator _rng;
public:
	//Time next();
	Time next();
};
Time RandomTimeGenerator::next() {
	int hour = _rng.next(0, 23);
	int minute = _rng.next(0, 59);
	int second = _rng.next(0, 59);
	Time result(hour, minute, second);
	return result;
}
int main()
{
	TimeToStringUIConverter converter;
	RandomTimeGenerator rdg;
	string infoTime;
	
	for (int i = 0; i < 10; i++) {
		Time time = rdg.next();
		cout << converter.convert(time) << endl;
	}
    return 0;
}

