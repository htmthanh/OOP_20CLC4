#pragma once
#include "RandomPointGenerator.h"
#include "Line.h"

class RandomLineGenerator {
private:
	RandomPointGenerator _rpg;
public:
	Line next();
};