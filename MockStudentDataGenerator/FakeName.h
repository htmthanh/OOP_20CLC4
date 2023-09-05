#pragma once
#include "Random.h"
class Fullname {
protected:
	string m_firstname;
	string m_middlename;
	string m_lastname;

public:
	Fullname();
	Fullname(string firstname, string middlename, string lastname);
	string shortened_name();
	string printf();
};

class FakeName :public Fullname {
public:
	Fullname next();
};
