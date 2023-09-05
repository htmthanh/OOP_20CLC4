// MockStudentDataGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Random.h"
#include "Date.h"
#include "FakeAddress.h"
#include "FakeBirthday.h"
#include "FakeEmail.h"
#include "FakeName.h"
#include "FakeTel.h"
#include "Student.h"
#include "StudentDataReader.h"
#include "RandomStudent.h"
#include <Windows.h>
void output(vector<Student> studentList){
	ofstream ofs;
	ofs.open("students.txt", ios::out);
	for (int i = 0; i < studentList.size(); i++) {
		ofs << "Student: " << studentList[i].id() << " - " << studentList[i].name() << endl;
		ofs << "\tGPA=" << studentList[i].gpa() << ", Telephone=" << studentList[i].tel() << endl;
		
		ofs << "\tEmail=" << studentList[i].email() << endl;
		ofs << "\tDOB=" << studentList[i].dob().toString() << endl;
		ofs << "\tAdresss=" << studentList[i].address().printf() << endl;
	}
	ofs.close();
}
int main() {
	vector<Student> studentList;
	StudentDataReader a("students.txt");
	
	studentList = a.read();
	cout << "Number of student in file : " << studentList.size() << endl;
	Random rng;

	int n=rng.next(5, 10);

	cout <<"Random n="<< n << endl;
	cout << "Waiting for random student......" << endl;
	RandomStudent rst;
	for (int i = 0; i < n; i++) {
		Student temp = rst.randomStudent();
		
		studentList.push_back(temp);
		Sleep(700);
	}
	for (int i = 0; i < studentList.size(); i++) {
		cout << studentList[i].toString() << endl;
	}
	output(studentList);

	float averageGPA = Student::caculateAverageGPA(studentList);
	cout << fixed << setprecision(2) <<endl<< "The average GPA of all students: " << averageGPA << endl;
	
	string printStudentGreaterGPA = Student::greaterThanAverageUIConverter(studentList);
	cout << endl << printStudentGreaterGPA << endl;
	cin.get();

	return 0;
}

