#include "RandomLineGenerator.h"

Line RandomLineGenerator::next() {
	Point a = _rpg.next();
	Point b = _rpg.next();

	Line result(a, b);
	return result;
}