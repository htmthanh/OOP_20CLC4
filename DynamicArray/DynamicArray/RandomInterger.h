#pragma once
#include <ctime>
#include <iostream>
using namespace std;
class RandomInterger
{
public:
	RandomInterger();
	int next();

	int next(int ceiling);
	int next(int min, int max);
	~RandomInterger();
	
};

