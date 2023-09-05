#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdarg.h>

using namespace std;

#include "Point.h"
#include "Line.h"
#include "RandomLineGenerator.h"
#include "RandomVietnamFullnameGenerator.h"

// Đừng cố gắng tách ra khai báo và cài đặt
// .h và .cpp
// meta programming
template <class MyType>
void permute(MyType& a, MyType& b) {
    MyType temp = a;
    a = b;
    b = temp;
}

class DynamicArray {
private:
    const int MAX = 128;
    const int STEP = 50;
private:
    int* _a;
    int _maxSize;
    int _currentSize;
public:
    DynamicArray() {        
        _a = new int[MAX];
        _maxSize = MAX;
        _currentSize = 0;
    }

    //Variadic arguments
    DynamicArray(vector<int> args) {
        _a = new int[MAX];
        _maxSize = MAX;
        _currentSize = 0;

        for (int i = 0; i < args.size(); i++) {
            int number = args[i]; 
            push_back(number);
       }
    }

    // maxSize = 5;
    // currentSize = 5
    // 
    // [1, 2, 3, 4, 5,              ]
    // list.push_back(6);

    // Move semantics
    void push_back(int value) {
        if (_currentSize == _maxSize) {
            _maxSize = _maxSize + STEP;

            // Cấp phát vùng nhớ mới
            int* temp = new int[_maxSize];

            // Lần lượt di chuyển dữ liệu cũ qua
            // cải tiến: move một block
            for (int i = 0; i < _currentSize; i++) {
                temp[i] = _a[i];
            }

            delete[] _a;
            _a = temp;
        }

        _a[_currentSize] = value;
        _currentSize++;
    }

    int size() {
        return _currentSize;
    }

    int getAt(int index) {
        if (index < 0 || index >= _currentSize) {
            throw exception("Index out of range");
        }

        return _a[index];
    }

    // index operator
    int operator[](int index) {
        return getAt(index);
    }

public:
    ~DynamicArray() {
        delete[] _a;
    }
};

int main()
{
    DynamicArray a({ 1, 3, 5, 7 });
    
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    

   /* int x = 5;
    int y = 10;
    permute<int>(x, y);
    cout << x << " " << y << endl;

    string left = "left";
    string right = "right";
    permute<string>(left, right);
    cout << left << " " << right << endl;

    bool success = true;
    bool failure = false;
    permute<bool>(success, failure);
    cout << success << " " << failure << endl;*/


    // Dynamic array
    /*vector<string> names = { "DInh", "Ly", "Tran", "Le" };
    cout << names[2];
    vector<bool> flags = { true, false, true, true, false };
    vector<char> vowels = { 'u', 'e', 'o', 'a', 'i' };*/

    /*RandomLineGenerator rlg;

    for (int i = 0; i < 5; i++) {
        Line line = rlg.next();
        cout << line.toString() << endl;
    }*/

    /*RandomVietnamFullnameGenerator rfg;
    for (int i = 0; i < 10; i++) {
        Fullname name = rfg.next();
        cout << name.getFullname() << endl;
    }*/

    cin.get();
    return 0;
}
