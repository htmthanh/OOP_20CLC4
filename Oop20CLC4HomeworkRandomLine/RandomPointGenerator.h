#pragma once
#include "RandomIntegerGenerator.h"
#include "Point.h"

class RandomPointGenerator {
private:
	RandomIntegerGenerator _rng;
public:
	Point next();
};