#pragma once
#include <fstream>
#include <sstream>
#include <cstring>
#include <regex>
#include <vector>
#include <iomanip>
#include "math.h"
#include <iostream>
using namespace std;
class Random
{
public:
	Random();
public:
	int next();

	int next(int ceiling);
	int next(int min, int max);

};
class RandomFloat {
public:
	RandomFloat(){}
public:
	float next(float min, float max) {
		float scale = rand() / (float)RAND_MAX; /* [0, 1.0] */
		float result= (min + scale * (max - min));
		float res = roundf(result*100) / 100;
		return res;
	}
};


