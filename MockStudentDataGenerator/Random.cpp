#include "stdafx.h"
#include "Random.h"


Random::Random()
{
	srand(time(NULL));
}
int Random::next() {
	int result = rand();
	return result;
}

int Random::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}
int Random::next(int min, int max) {
	int result = min + rand() % (max + 1 - min);
	return result;
}


