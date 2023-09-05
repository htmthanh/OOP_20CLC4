#pragma once
#include"Random.h"
#include <regex>
class Address
{
protected:
	int m_number;
	string m_street;
	string m_ward;
	string m_district;
	string m_city;

public:
	Address();
	Address(int, string, string, string, string);
	string getWard() { return m_ward; }
	string getDistrict() { return m_district; }
	void setNum(int num) {
		m_number = num;
	}
	void setStreet(string street) {
		m_street = street;
	}
	void setWard(string ward) {
		m_ward = ward;
	}
	void setDistrict(string district) {
		m_district = district;
	}
	void setCity(string city) {
		m_city = city;
	}
	string printf();

};

class FakeHcmAddress :public Address
{
public:
	Address next();

};

