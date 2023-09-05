#include "RandomIntegerGenerator.h"
#include <iostream>
using namespace std;

RandomIntegerGenerator::RandomIntegerGenerator() {
	srand(time(NULL));
}

int RandomIntegerGenerator::next() {
	int result = rand();
	return result;
}

int RandomIntegerGenerator::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}

int RandomIntegerGenerator::next(int left, int right) {
	int result = rand() % (right - left + 1) + left;
	return result;
}