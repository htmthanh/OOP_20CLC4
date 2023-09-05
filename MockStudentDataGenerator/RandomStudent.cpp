#include "stdafx.h"
#include "RandomStudent.h"
#include <Windows.h>


Student RandomStudent::randomStudent() {
	//Random rng;
	int id = _rng.next(2127000, 2127777);
	string email = FakeEmail();
	
	//FakeName a;
	//Fullname name = a.next();
	//string ranname = "huynh thi my thanh";
	string name = na.next().printf();
	Sleep(700);
	string phone = FakeTel();
	//FakeBirthday birth;
	Date dob = birth.next();
	//RandomFloat tb;
	//FakeHcmAddress ad;
	Address address = ad.next();
	Sleep(700);
	float gpa = tb.next(0.0, 10.0);
	Student result(id, name, gpa, phone, email, dob, address);
	return result;

}


