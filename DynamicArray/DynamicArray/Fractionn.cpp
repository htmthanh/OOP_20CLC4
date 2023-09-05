#include "stdafx.h"
#include "Fractionn.h"

Fraction::Fraction()
{
	int num = 0;
	int denom = 1;
}
Fraction::Fraction(int num, int denom) {
	_num = num;
	_denom = denom;
}
int Fraction::num(){ 
	return _num;
}

int Fraction::denom() { 
	return _denom;
}

void Fraction::setNum(int value) { 
	_num = value; 
}
void Fraction::setDenom(int value) { 
	_denom = value; 
}
int Fraction::gcd(int a, int b) {
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
Fraction Fraction::lowest() {
	int num = _num / gcd(_num, _denom);
	int denom = _denom / gcd(_num, _denom);
	return Fraction(num, denom);
}
Fraction Fraction::add(Fraction &a) {
	Fraction result;
	result._num = _num*a.denom() + a.num()*_denom;
	result._denom = _denom*a.denom();
	Fraction final = result.lowest();
	return final;
}
string Fraction::toString() {
	stringstream out;
	out << "Num: " << _num << ",  Denom: " << _denom << endl;;
	return out.str();
}
Fraction::~Fraction(){
	
}