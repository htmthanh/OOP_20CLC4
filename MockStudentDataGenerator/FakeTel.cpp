#include "stdafx.h"
#include "FakeTel.h"


string FakeTel()
{
	string tel;
	Random rng;

	string first_tel[] = { "032","033","034","035","036","037","038","039","070","079","077","076","078","083","084","085","081","082","056","058" };
	for (int i = 0; i < rng.next(sizeof(first_tel) / sizeof(string) - 1) + 1; i++)
		tel = first_tel[i];

	tel += to_string(rng.next(0, 9)) + "-";
	for (int i = 0; i < 3; i++) {
		tel += to_string(rng.next(9));
	}
	tel += "-";
	for (int i = 0; i < 3; i++) {
		tel += to_string(rng.next(9));
	}
	return tel;
}
