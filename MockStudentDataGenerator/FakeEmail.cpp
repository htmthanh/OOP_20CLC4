#include "stdafx.h"
#include "FakeEmail.h"


string FakeEmail()
{
	FakeName name;
	string email = name.next().shortened_name() + "@student.hcmus.edu.vn";
	//Random rng;

	//string domain[] = { "gmail.com","microsoft.com","apple.com","amazon.com","facebook.com","twitter.com","google.com","yahoo.com","ask.com","ebay.com" };
	//for (int i = 0; i < rng.next(sizeof(domain) / sizeof(string) - 1) + 1; i++)
		//temp = domain[i];
	//temp = "student.hcmus.edu.vn";
	//email += temp;

	return email;
}