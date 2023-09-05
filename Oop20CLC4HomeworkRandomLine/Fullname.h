#pragma once
#include <string>
using namespace std;

class Fullname {
private:
	string _firstname;
	string _middlename;
	string _lastname;
public:
	string getFirstname();
	string getMiddlename();
	string getLastname();
	
	void setFirstname(string);
	void setMiddlename(string);
	void setLastname(string);

	string getFullname();
public:
	Fullname();
	Fullname(string, string, string);
public:
	string toString();
};