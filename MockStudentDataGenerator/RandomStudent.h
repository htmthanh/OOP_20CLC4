#pragma once
#include "Student.h"
#include "Random.h"
#include "FakeAddress.h"
#include "FakeBirthday.h"
#include "FakeEmail.h"
#include "FakeName.h"
#include "FakeTel.h"

class RandomStudent:public Student
{
private:
	Random _rng;
	FakeBirthday birth;
	FakeHcmAddress ad;
	FakeName na;
	RandomFloat tb;
public:

	RandomStudent(){}
public:

	Student randomStudent();

};

