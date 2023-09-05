#include "stdafx.h"
#include "FakeAddress.h"


Address::Address()
{
	m_number = 0;
	m_street = m_ward = m_district = m_city = { "" };
}

Address::Address(int number, string street, string ward, string district, string city)
{
	m_number = number;
	m_street = street;
	m_ward = ward;
	m_district = district;
	m_city = city;
}

string Address::printf()
{
	stringstream builder;

	builder << m_number << " " << m_street << ",";
	const string pattern = "\\b\\d+\\b";
	regex numberPattern(pattern);
	if (regex_match(m_ward,numberPattern)) {
		builder << " Ward " << m_ward;
		
	}
	else
		builder << " " << m_ward << " Ward";
	builder << ", ";
	if (regex_match(m_district, numberPattern)) {
		builder << "District " << m_district << ",";
	}
	else builder << m_district << " District,";
	builder << " " << m_city<<" city";
	string result = builder.str();
	return result;
}


Address FakeHcmAddress::next()
{
	Random rng;

	string Ward1[] = { "Tan Dinh","Da Kao","Ben Nghe","Ben Thanh","Nguyen Thai Binh","Pham Ngu Lao","Nguyen Cu Trinh","Cau Kho" };
	string Street1[] = { "Nguyen Van Cu","Bui Vien","Ly Tu Trong","Nguyen Du","Nguyen Hue" };

	string Ward2[] = { "Thao Dien","An Phu","Binh An","Binh Khanh","An Khanh","Cat Lai","An Loi Dong","Thu Thiem" };
	string Street2[] = { "Nguyen Duy Hieu","Nguyen Duy Trinh","Nguyen Hoang","Nguyen Thi Dinh","Song Hanh" };

	string Ward3[] = { "1","2","3","4","5","6","7","8" };
	string Street3[] = { "Nguyen Tri Phuong","Hoa Hung","Hoang Sa","Le Quy Don","Le Van Si" };

	string Ward4[] = { "1","2","3","4","5","6","7","8" };
	string Street4[] = { "Nguyen Khoai","Ton That Huyet","Ton Dan","Vinh Hoi","Hoang Dieu" };

	string Ward5[] = { "1","2","3","4","5","6","7","8" };
	string Street5[] = { "Nguyen Van Cu","An Duong Vuong","Le Hong Phong","Van Kiep","Hong Bang" };


	m_city = "Ho Chi Minh";

	string District[] = { "1","2", "3", "4", "5" };
	for (int i = 0; i < rng.next(sizeof(District) / sizeof(string) - 1) + 1; i++)
		m_district = District[i];

	int district = stoi(m_district);
	switch (district)
	{
	case 1:
		for (int i = 0; i < rng.next(sizeof(Ward1) / sizeof(string) - 1) + 1; i++)
			m_ward = Ward1[i];

		for (int i = 0; i < rng.next(sizeof(Street1) / sizeof(string) - 1) + 1; i++)
			m_street = Street1[i];

		break;

	case 2:
		for (int i = 0; i < rng.next(sizeof(Ward1) / sizeof(string) - 1) + 1; i++)
			m_ward = Ward2[i];

		for (int i = 0; i < rng.next(sizeof(Street1) / sizeof(string) - 1) + 1; i++)
			m_street = Street2[i];

		break;

	case 3:
		for (int i = 0; i < rng.next(sizeof(Ward1) / sizeof(string) - 1) + 1; i++)
			m_ward = Ward3[i];

		for (int i = 0; i < rng.next(sizeof(Street1) / sizeof(string) - 1) + 1; i++)
			m_street = Street3[i];

		break;

	case 4:
		for (int i = 0; i < rng.next(sizeof(Ward1) / sizeof(string) - 1) + 1; i++)
			m_ward = Ward4[i];

		for (int i = 0; i < rng.next(sizeof(Street1) / sizeof(string) - 1) + 1; i++)
			m_street = Street4[i];

		break;

	case 5:
		for (int i = 0; i < rng.next(sizeof(Ward1) / sizeof(string) - 1) + 1; i++)
			m_ward = Ward5[i];

		for (int i = 0; i < rng.next(sizeof(Street1) / sizeof(string) - 1) + 1; i++)
			m_street = Street5[i];

		break;
	}

	m_number = rng.next(1000) + 1;

	Address add(m_number, m_street, m_ward, m_district, m_city);
	return add;
}
