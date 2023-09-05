#include "stdafx.h"
#include "StudentDataReader.h"


vector<Student> StudentDataReader::read() {
	vector<Student> res;
	ifstream ifs(_fname);

	int id;
	string buffer, name, tel, email;
	float gpa;
	string temp;
	Date dob;
	Address address;
	while (!ifs.eof()) {
		getline(ifs, buffer);
		if (buffer == "")break;
		int firstIndex = buffer.find(' ') + 1;
		int lastIndex = buffer.find('-') - 2;
		temp = buffer.substr(firstIndex, lastIndex - firstIndex + 1);
		id = stoi(temp);
		//firstIndex=buffer.find('-')
		temp = buffer.substr(buffer.find('-') + 2, buffer.length() - buffer.find('-') - 1);
		// = 
		name = temp;
		getline(ifs, buffer);
		gpa = stof(buffer.substr(buffer.find('=') + 1, buffer.find(',') - buffer.find('=') - 1));
		buffer = buffer.substr(buffer.find(',') + 1, buffer.length() - buffer.find(','));
		tel = buffer.substr(buffer.find('=') + 1, buffer.length() - buffer.find('='));
		getline(ifs, buffer);
		email = buffer.substr(buffer.find('=') + 1, buffer.length() - buffer.find('='));
		getline(ifs, buffer);
		buffer = buffer.substr(buffer.find('=') + 1, buffer.length() - buffer.find('='));
		dob.parse(buffer);
		getline(ifs, buffer);
		buffer = buffer.substr(buffer.find('=') + 1, buffer.length() - buffer.find('='));
		address.setNum(stoi(buffer.substr(0, buffer.find(' '))));
		address.setStreet(buffer.substr(buffer.find(' ') + 1, buffer.find(',') - buffer.find(' ') - 1));
		buffer = buffer.substr(buffer.find(',') + 2, buffer.length() - buffer.find(',') - 2);
		if (buffer.find("Ward,") != -1) {
			address.setWard(buffer.substr(0, buffer.find(" Ward,")));
		}
		else {
			address.setWard(buffer.substr(buffer.find(' ') + 1, buffer.find(',') - buffer.find(' ') - 1));
		}
		buffer = buffer.substr(buffer.find(',') + 2, buffer.length() - buffer.find(',') - 2);
		if (buffer.find("District,") != -1) {
			address.setDistrict(buffer.substr(0, buffer.find(" District,")));
		}
		else {
			address.setDistrict(buffer.substr(buffer.find(' ') + 1, buffer.find(',') - buffer.find(' ') - 1));
		}
		buffer = buffer.substr(buffer.find(',') + 2, buffer.size() - buffer.find(',') - 2);
		address.setCity(buffer.substr(0, buffer.find(" city")));
		Student tmp(id, name, gpa, tel, email, dob, address);
		res.push_back(tmp);
	}
	ifs.close();
	return res;
}
