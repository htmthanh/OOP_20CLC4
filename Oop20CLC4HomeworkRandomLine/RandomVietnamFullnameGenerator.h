#pragma once
#include "RandomIntegerGenerator.h"
#include "Fullname.h"

class RandomVietnamFullnameGenerator {
private:
	RandomIntegerGenerator _rng;
public:
	Fullname next();
};