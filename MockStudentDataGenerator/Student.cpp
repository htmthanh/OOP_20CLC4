#include "stdafx.h"
#include "Student.h"
Student::Student(int id, string name, float gpa, string tel, string mail, Date dob, Address address) {
	_ID=id;
	_name=name;
	_gpa=gpa;
	_tel=tel;
	_email=mail;
	_dob=dob;
	_address=address;
}
float Student::caculateAverageGPA(vector<Student> listStudent) {
	float sum = 0;
	for (int i = 0; i < listStudent.size(); i++) {
		sum += listStudent[i].gpa();

	}
	return sum / listStudent.size();
}
string Student::greaterThanAverageUIConverter(vector<Student>listStudent) {
	float averageGPA = caculateAverageGPA(listStudent);
	stringstream builder;
	for (int i = 0; i < listStudent.size(); i++) {
		if (listStudent[i].gpa() >= averageGPA) {
			builder << listStudent[i].id() << "-" << listStudent[i].name() << ", GPA:" << fixed << setprecision(2) << listStudent[i].gpa() << endl;
		}
	}
	string result = builder.str();
	return result;
}
