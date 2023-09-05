// EmployeeSalary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <regex>
#include <vector>
#include <iomanip>
#include "math.h"
#include <iostream>
#include <memory>
#include <map>
using namespace std;
class Employee;
class EmployeeFactory;
class DailyEmployee;
class HourlyEmployee;
class ProductEmployee;
class Manager;
class Tokenizer
{
public:
	static vector<string> split(string haystack, string separator, bool removeEmptyEntries = true)
	{
		vector<string> result;

		int startPos = 0;
		size_t foundPos;

		while (1) {
			foundPos = haystack.find(separator, startPos);

			if (foundPos != string::npos) {
				string token = haystack.substr(startPos, foundPos - startPos);
				result.push_back(token);

				startPos = foundPos + separator.length();
			}
			else {
				string token = haystack.substr(startPos, haystack.length() - startPos);
				result.push_back(token);

				break;
			}
		}
		return result;
	}
};

class Employee {
public:
	virtual int salary() = 0;
	virtual string toString() = 0;
	virtual void parseName(string) = 0;
	virtual void parsePay(string) = 0;
	virtual string magicWord() = 0;
	virtual string SalaryString() = 0;
	virtual shared_ptr<Employee> clone() = 0;
};
class DailyEmployee : virtual public Employee {
private:
	string _fullname;
	int _dailypayment;
	int _totalday;
public:
	string getName() { return _fullname; }
	int getPay() { return _dailypayment; }
	int getTotalday() { return _totalday; }
	string magicWord() { return "DailyEmployee"; }
	shared_ptr<Employee> clone() { return make_shared<DailyEmployee>(); }
	DailyEmployee(){}
	DailyEmployee(string name, int pay, int total) {
		_fullname = name;
		_dailypayment = pay;
		_totalday = total;
	}
	void setName(string name) { _fullname = name; }
	void setPay(int pay) { _dailypayment = pay; }
	void setTotal(int total) { _totalday = total; }
	void parseName(string name) {
		int index = name.find(":");
		setName(name.substr(index + 2, name.size()));
	}
	void parsePay(string pay) {
		int index = pay.find_first_of("=");
		int last = pay.find_first_of("$");
		string payment = pay.substr(index + 1, last - 1);
		setPay(stoi(payment));
		int index2 = pay.find_last_of("=");
		string daytotal = pay.substr(index2 + 1, pay.size());
		setTotal(stoi(daytotal));
	}
	
	int salary() {
		int result = getPay()*getTotalday();
		return result;
	}
	string toString() {
		stringstream builder;
		builder << magicWord() <<": "<< getName() << endl;
		builder << "\tDailyPayment=" << getPay() << "$; TotalDays=" << getTotalday();
		string result = builder.str();
		return result;
	}
	string SalaryString() {
		stringstream builder;
		builder << "\tFINAL PAYMENT: " << salary() << "$";
		string result = builder.str();
		return result;
	}
};
class HourlyEmployee :virtual public Employee {
private:
	string _fullname;
	int _hourlypayment;
	int _totalhour;
public:
	string getName() { return _fullname; }
	int getPay() { return _hourlypayment; }
	int getTotal() { return _totalhour; }
	string magicWord() { return "HourlyEmployee"; }
	shared_ptr<Employee> clone() { return make_shared<HourlyEmployee>(); }
	HourlyEmployee() {}
	HourlyEmployee(string name, int pay, int total) {
		_fullname = name;
		_hourlypayment = pay;
		_totalhour = total;
	}
	void setName(string name) { _fullname = name; }
	void setPay(int pay) { _hourlypayment = pay; }
	void setTotal(int total) { _totalhour = total; }
	int salary() {
		int result = getPay() * getTotal();
		return result;
	}
	void parseName(string name) {
		int index = name.find(":");
		setName(name.substr(index + 2, name.size()));
	}
	void parsePay(string pay) {
		int index = pay.find_first_of("=");
		int last = pay.find_first_of("$");
		string payment = pay.substr(index + 1, last - 1);
		setPay(stoi(payment));
		int index2 = pay.find_last_of("=");
		string hourtotal = pay.substr(index2 + 1, pay.size());
		setTotal(stoi(hourtotal));
	}
	string toString() {
		stringstream builder;
		builder << magicWord() << ": " << getName() << endl;
		builder << "\tHourlyPayment=" << getPay() << "$; TotalHours=" << getTotal();
		string result = builder.str();
		return result;
	}
	string SalaryString() {
		stringstream builder;
		builder << "\tFINAL PAYMENT: " << salary() << "$";
		string result = builder.str();
		return result;
	}
};
class ProductEmployee :virtual public Employee {
private:
	string _fullname;
	int _productpayment;
	int _totalproduct;
public:
	string getName() { return _fullname; }
	int getPay() { return _productpayment; }
	int getTotal() { return _totalproduct; }
	string magicWord() { return "ProductEmployee"; }
	shared_ptr<Employee> clone() { return make_shared<ProductEmployee>(); }
	ProductEmployee() {}
	ProductEmployee(string name, int pay, int total) {
		_fullname = name;
		_productpayment = pay;
		_totalproduct = total;
	}
	void setName(string name) { _fullname = name; }
	void setPay(int pay) { _productpayment = pay; }
	void setTotal(int total) { _totalproduct = total; }
	int salary() {
		int result = getPay() * getTotal();
		return result;
	}
	void parseName(string name) {
		int index = name.find(":");
		setName(name.substr(index + 2, name.size()));
	}
	void parsePay(string pay) {
		int index = pay.find_first_of("=");
		int last = pay.find_first_of("$");
		string payment = pay.substr(index + 1, last - 1);
		setPay(stoi(payment));
		int index2 = pay.find_last_of("=");
		string producttotal = pay.substr(index2 + 1, pay.size());
		setTotal(stoi(producttotal));
	}
	string toString() {
		stringstream builder;
		builder << magicWord() << ": " << getName() << endl;
		builder << "\tPaymentPerProduct=" << getPay() << "$; TotalDays=" << getTotal();
		string result = builder.str();
		return result;
	}
	string SalaryString() {
		stringstream builder;
		builder << "\tFINAL PAYMENT: " << salary() << "$";
		string result = builder.str();
		return result;
	}
};
class Manager :virtual public Employee {
private:
	string _fullname;
	int _fixedpayment;
	int _total;
	int _paymenperemployee;
public:
	string getName() { return _fullname; }
	int getFix() { return _fixedpayment; }
	int getPay() { return  _paymenperemployee; }
	int getTotal() { return  _total; }
	string magicWord() { return "Manager"; }
	shared_ptr<Employee> clone() { return make_shared<Manager>(); }
	Manager() {}
	Manager(string name, int payfix,int pay, int total) {
		_fullname = name;
		_fixedpayment = payfix;
		_paymenperemployee = pay;
		_total = total;
	}
	void setName(string name) { _fullname = name; }
	void setPayFix(int fix) { _fixedpayment = fix; }
	void setPay(int pay) { _paymenperemployee = pay; }
	void setTotal(int total) { _total = total; }
	int salary() {
		int result = getPay() * getTotal()+getFix();
		return result;
	}
	void parseName(string name) {
		int index = name.find(":");
		setName(name.substr(index + 2, name.size()));
	}
	void parsePay(string pay) {
		vector<string> token = Tokenizer::split(pay, ";");
		int index = token[0].find_first_of("=");
		int last = token[0].find_first_of("$");
		string fixed = token[0].substr(index + 1, last - 1);
		setPayFix(stoi(fixed));
		int index1 = token[1].find_first_of("=");
		string total = token[1].substr(index1 + 1, token[1].size());
		setTotal(stoi(total));
		int index2 = token[2].find_first_of("=");
		int last2 = token[2].find_first_of("$");
		string paymentEmployee = token[2].substr(index2 + 1, last2 - 1);
		setPay(stoi(paymentEmployee));
	}
	string toString() {
		stringstream builder;
		builder << magicWord() << ": " << getName() << endl;
		builder << "\tFixedPayment=" << getFix() << "$; TotalEmployees=" << getTotal()<<"; PaymentPerEmployee="<<getPay()<<"$";
		string result = builder.str();
		return result;
	}
	string SalaryString() {
		stringstream builder;
		builder << "\tFINAL PAYMENT: " << salary() << "$";
		string result = builder.str();
		return result;
	}
};
class EmployeeFactory {
public:
	map<string, shared_ptr<Employee>> _prototypes;
private:
	static shared_ptr<EmployeeFactory> _instance;
	EmployeeFactory() {
		auto daily = make_shared<DailyEmployee>();
		auto hourly = make_shared<HourlyEmployee>();
		auto product = make_shared<ProductEmployee>();
		auto manager = make_shared<Manager>();

		_prototypes.insert({ "DailyEmployee",daily });
		_prototypes.insert({ "HourlyEmployee",hourly });
		_prototypes.insert({ "ProductEmployee",product });
		_prototypes.insert({ "Manager",manager });


	}
public:
	static shared_ptr<EmployeeFactory> getInstance() {
		if (_instance == nullptr) {
			auto temp = new EmployeeFactory();
			_instance = shared_ptr<EmployeeFactory>(temp);
		}
		return _instance;
	}
	shared_ptr<Employee> createEmployee(string employ) {
		auto it = _prototypes[employ];
		shared_ptr<Employee> result = it->clone();
		return result;
	}
	void printAll(vector<shared_ptr<Employee>>employees) {
		for (auto it = employees.begin(); it != employees.end(); it++) {
			cout << (*it)->toString() << endl;
		}
	}
	void Read(string filename) {
		ifstream ifs;
		ifs.open(filename, ios::in);
		string buffer;
		shared_ptr<Employee> employee;
		//_prototypes.clear();
		vector<shared_ptr<Employee>> result;
		while (!ifs.eof()) {
			getline(ifs, buffer);
			if (buffer.find("DailyEmployee") != -1) {
				//int firstIndex = buffer.find(" ");
				//employee = make_shared<DailyEmployee>();
				employee = _prototypes["DailyEmployee"];
				employee->parseName(buffer);
				getline(ifs, buffer);
				employee->parsePay(buffer);
				result.push_back(employee);
				//_prototypes.insert({ employee->magicWord(),employee });
				//cout << employee->magicWord() << " " <<
				//	_prototypes.at(employee->magicWord())->toString() 
					//<< endl;
				cout << employee->toString() << endl;
				cout << employee->SalaryString() << endl;
			}
			else if (buffer.find("HourlyEmployee") != -1) {
				//int firstIndex = buffer.find(" ");
				//employee = make_shared<HourlyEmployee>();
				employee = _prototypes["HourlyEmployee"];
				employee->parseName(buffer);
				getline(ifs, buffer);
				employee->parsePay(buffer);
				result.push_back(employee);
				//_prototypes.insert({ employee->magicWord(),employee });
				//cout << employee->magicWord() << " " <<
				//	_prototypes.at(employee->magicWord())->toString()
				//	<< endl;
				cout << employee->toString() << endl;
				cout << employee->SalaryString() << endl;
			}
			else if (buffer.find("ProductEmployee") != -1) {
				//int firstIndex = buffer.find(" ");
				//employee = make_shared<ProductEmployee>();
				employee = _prototypes["ProductEmployee"];
				employee->parseName(buffer);
				getline(ifs, buffer);
				employee->parsePay(buffer);
				result.push_back(employee);
				//_prototypes.insert({ employee->magicWord(),employee });
				//cout << employee->magicWord() << " " <<
				//	_prototypes.at(employee->magicWord())->toString()
				//	<< endl;
				cout << employee->toString() << endl;
				cout << employee->SalaryString() << endl;
			}
			else if (buffer.find("Manager") != -1) {
				//int firstIndex = buffer.find(" ");
				//employee = make_shared<Manager>();
				employee = _prototypes["Manager"];
				employee->parseName(buffer);
				getline(ifs, buffer);
				employee->parsePay(buffer);
				result.push_back(employee);
				//_prototypes.insert({ employee->magicWord(),employee });
				//cout << employee->magicWord() << " " <<
				//	_prototypes.at(employee->magicWord())->toString()
				//	<< endl;
				cout << employee->toString() << endl;
				cout << employee->SalaryString() << endl;
			}
		}
	}
};
shared_ptr<EmployeeFactory> EmployeeFactory::_instance = NULL;
int main()
{
	auto employee = EmployeeFactory::getInstance();
	employee->Read("November2021.txt");
    return 0;
}

