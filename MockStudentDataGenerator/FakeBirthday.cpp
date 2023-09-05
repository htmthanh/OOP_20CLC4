#include "stdafx.h"
#include "FakeBirthday.h"


Date FakeBirthday::next()
{
	Random rng;

	m_year =2001;
	m_month = rng.next(1, 12);
	m_day = rng.next(1, 31);

	string date = toString();
	while (isValid(date) == false) {
		m_day = rng.next(1, 31);
		date = toString();
	}

	return *this;
}

Date FakeBirthday::next(int year)
{
	Random rng;

	m_year = year;
	m_month = rng.next(1, 12);
	m_day = rng.next(1, 31);

	string date = toString();
	while (isValid(date) == false) {
		m_day = rng.next(1, 31);
		date = toString();
	}

	return *this;
}
