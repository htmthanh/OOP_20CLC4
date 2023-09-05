#include "stdafx.h"
#include "RandomInterger.h"

RandomInterger::RandomInterger()
{
	srand(time(NULL)); // Current time
}
int RandomInterger::next() {
	int result = rand();
	return result;
}
int RandomInterger::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}

int RandomInterger:: next(int min, int max) {
	int result = min + rand() % (max + 1 - min);
	return result;
}

RandomInterger::~RandomInterger()
{

}
