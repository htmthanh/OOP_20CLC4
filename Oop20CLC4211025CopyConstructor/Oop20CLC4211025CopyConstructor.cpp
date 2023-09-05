// Oop20CLC4211025CopyConstructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
using namespace std;

// Passing by reference Using pointers as parameters
void Swap1(int* a, int* b) {
    int temp = *a; // asterisk: dereference operator
    *a = *b;
    *b = temp;
}

// Passing by reference Using references as parameters
void Swap2(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class Cat {
private:
    string _name;
    float _weight;
    float _height;
public:
    // Parameterized constructor
    Cat(string name, float weight, float height) {
        _name = name;
        _weight = weight;
        _height = height;
    }
public:
    string toString() {
        stringstream builder;

        builder << _name << ": Weight=" << _weight
            << ", Height:" << _height;

        string result = builder.str();
        return result;
    }
};

class DynamicArray {
private:
    const int InitialSize = 128;
private:
    int* _a = NULL;
    int _maxSize;
    int _currentSize;
public:
    DynamicArray() {
        _a = new int[InitialSize];
        _maxSize = InitialSize;
        _currentSize = 0;
    }

    // Deep copy
    DynamicArray(const DynamicArray& other) {
        cout << "Copy constructor is called" << endl;

        this->_a = new int[other._maxSize];
        // Copy back all elements
        for (int i = 0; i < other._currentSize; i++) {
            this->_a[i] = other._a[i];
        }
        
        this->_maxSize = other._maxSize;
        this->_currentSize = other._currentSize;
    }

    // Handle: overflow our prepared array
    void push(int newItem) {
        _a[_currentSize] = newItem;
        _currentSize++;
    }

    // catch Out of bound exception
    int& operator[](int index) {
        return _a[index];
    }

    int size() { return _currentSize; }
    // a = b = c = d = e;
    // d.operator=(e) return e
    // c = e; c.operator=(e) return e
    // b = e; b.operator=(e)
    // a = e; a.operator=(e)
    const DynamicArray& operator=(const DynamicArray& other) {
        cout << "The operator = is called" << endl;

        if (this->_a != NULL) {
            delete[] this->_a;
        }

        this->_a = new int[other._maxSize];
        // Copy back all elements
        for (int i = 0; i < other._currentSize; i++) {
            this->_a[i] = other._a[i];
        }

        this->_maxSize = other._maxSize;
        this->_currentSize = other._currentSize;

        return other;
    }

public:
    ~DynamicArray() {
        if (_a != NULL) {
            delete[] _a;
        }
    }
};


// Declaration
class Integer {
public:
    static int gcd(int a, int b);
};

class IntegerToStringUIConverter {
public:
    string convert(const int& number) {
        stringstream builder;

        builder << number;

        string result = builder.str();
        return result;
    }

    int convertBack(string value) {
        int result = 0;

        if (isValidFormat(value)) {
            result = stoi(value);
        }

        return result;
    }

    bool tryConvertBack(string value, int& number) {
        bool result = true;

        if (isValidFormat(value)) {
            int parsedNumber = stoi(value);
            number = parsedNumber;
        }
        else {
            result = false;
        }

        return result;
    }
    
    bool isValidFormat(string value) 
    {
        const regex DigitsPattern("\\b\\d+\\b");

        bool result = regex_match(value, DigitsPattern);
        return result;
    }
};


int main()
{
    string buffer = "12/23";
    int firstIndex = buffer.find_first_of("/");
    cout << firstIndex << endl;
    string numString = buffer.substr(0, firstIndex);
    cout << numString << endl;
    cout << buffer.size() << endl;

    string denString = buffer.substr(
        firstIndex + 1, buffer.size() - firstIndex - 1);
    cout << denString << endl;

    // Regular expression
    // string pattern = "d+/d+";
    // if matched 

    // bool isValidFormat(string value, string pattern);
    // int parse(string value); // throw exception nếu có vấn đề
    // bool tryParse(string value, Fraction& f);

    //Fraction f;
    //bool result = tryParse("7//9", &f);

    //if (result == true) {

    //}
    //else {
    //    // Nhập lại
    //}
 


    /*DynamicArray a;
    a.push(6);
    a.push(7);
    a.push(12);
    a.push(13);
    a.push(14);*/

    //// output file stream
    //ofstream writer;
    //string filename = "data.txt";
    //writer.open(filename, ios::out);

    //// Mỗi dòng là một số
    //for (int i = 0; i < a.size(); i++) {
    //    writer << a[i] << endl;
    //}

    //writer.close();

    // input file
    //ifstream reader;
    //string filename = "data.txt";
    //reader.open(filename, ios::in);

    //DynamicArray b;

    //while (!reader.eof()) {
    //    string buffer;
    //    getline(reader, buffer);

    //    try {
    //        int number = stoi(buffer);
    //        b.push(number);
    //    }
    //    catch (exception ex) {
    //        // Eat the exception
    //    }
    //}

    //reader.close();

    //for (int i = 0; i < b.size(); i++) {
    //    cout << b[i] << " ";
    //}
    //cout << endl;


    //DynamicArray b;
    //b.push(111);
    //b.push(222);
    //b.push(333);
    //b.push(444);

    //cout << "This is out originial array:" << endl;
    //for (int i = 0; i < a.size(); i++) {
    //    cout << a[i] << " ";
    //}
    //cout << endl;

    //DynamicArray temp(a);

    //// First, if element < 12, please double it
    //for (int i = 0; i < temp.size(); i++) {
    //    if (temp[i] < 12) {
    //        temp[i] = temp[i] * 2;
    //    }
    //}

    //cout << "After processing..." << endl;

    //// Print out the computed array
    //for (int i = 0; i < a.size(); i++) {
    //    cout << a[i] << " ";
    //}
    //cout << endl;

    //// Print out the computed array
    //for (int i = 0; i < temp.size(); i++) {
    //    cout << temp[i] << " ";
    //}
    //cout << endl;

    //temp = b;

    //DynamicArray newPlayer = b;




    /*Cat cat1("Doraemon", 50, 1.1);
    Cat temp(cat1);

    cout << cat1.toString() << endl;
    cout << temp.toString() << endl;*/


    //Cat cat2("Mimi", 40, 1);
    //Cat cat3("Kitty", 6, 0.3);
   
    //cout << cat3.toString() << endl;


    //int x = 5;
    //int y = 10;

    ////Swap1(&x, &y); // operator to get the address of the variable
    //Swap2(x, y);


    //cout << "x=" << x << ", ";
    //cout << "x=" << y << endl;

    cin.get();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
