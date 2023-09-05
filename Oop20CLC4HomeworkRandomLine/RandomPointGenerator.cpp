#include "RandomPointGenerator.h"

// Three types
// Entity - Data class (store data) Point
// Business logic PointBusiness
// Data access saving / loading / convert  POintData

Point RandomPointGenerator::next() {
	int x = _rng.next();
	int y = _rng.next();

	Point result(x, y);
	return result;
}