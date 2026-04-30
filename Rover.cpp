// provided. do not modify. do not submit.
#include <iostream>
#include "Rover.h"
#include "MyString.h"

using std::cout, std::endl;

void Rover::print() {
    cout << smile_ << endl;  // uses `MyString::operator<<`
}

void Rover::read(int n) {
    cout << smile_.at(n) << endl;  // uses `MyString::at`
}

void Rover::clear() {
    if (!smile_.empty()) {  // uses `MyString::empty`
        smile_.clear();  // uses `MyString::clear`
    }
}

void Rover::join(MyString input) {
    smile_ += input;  // uses `MyString::operator+=()
}

MyString Rover::test(MyString input) {
    MyString tester(smile_);  // uses `MyString` copy constructor
    tester += input;  // uses `MyString::operator+=`
    return tester;  // uses `MyString` destructor (implicitly, for `input`)
}

bool Rover::find(MyString search) {
    int index = smile_.find(search);  // uses `MyString::find`
    return index >= 0;
}
