#include "RandomVietnamFullnameGenerator.h"

Fullname RandomVietnamFullnameGenerator::next() {
	string firsts[] = { "A1", "A2", "A3" };
	string middles[] = { "B1", "B2", "B3" };
	string lasts[] = { "C1", "C2", "C3" };

	string first = firsts[_rng.next(3)];
	string middle = middles[_rng.next(3)];
	string last = lasts[_rng.next(3)];

	Fullname result(first, middle, last);
	return result;
}