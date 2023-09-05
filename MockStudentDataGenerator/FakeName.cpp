#include "stdafx.h"
#include "FakeName.h"


Fullname::Fullname()
{
	m_firstname = m_middlename = m_lastname = { "" };
}

Fullname::Fullname(string firstname, string middlename, string lastname)
{
	m_firstname = firstname;
	m_middlename = middlename;
	m_lastname = lastname;
}

string Fullname::shortened_name()
{
	string name = m_firstname.substr(0, 1) + m_middlename.substr(0, 1) + m_lastname;

	return name;
}

string Fullname::printf()
{
	stringstream builder;
	builder << m_firstname << " " << m_middlename << " " << m_lastname;
	string result = builder.str();
	return result;
}


Fullname FakeName::next()
{
	Random rng;

	string first[] = { "Nguyen","Tran","Ho","Pham","Le","Ly","Huynh","Hoang","Phan","Vu","Vo","Dang","Bui","Do","Doan" };
	for (int i = 0; i < rng.next(sizeof(first) / sizeof(string) - 1) + 1; i++)
		m_firstname = first[i];

	string middle[] = { "Van","Thi","Hoai","Tien","Kim","Thuy","Thanh","Huu","My","Quang" };
	for (int i = 0; i < rng.next(sizeof(middle) / sizeof(string) - 1) + 1; i++)
		m_middlename = middle[i];

	string last[] = { "Anh","Binh","Cuong","Duong","Huong","Hanh","Ha","Linh","Lien","Khang","Yruc","Han","Vy","Thu","Phong" };
	for (int i = 0; i < rng.next(sizeof(last) / sizeof(string) - 1) + 1; i++)
		m_lastname = last[i];

	Fullname name(m_firstname, m_middlename, m_lastname);

	return name;
}