// provided. do not modify. do not submit.
#include <iostream>
#include <fstream>
#include "Rover.h"
#include "MyString.h"

using std::cin, std::cout, std::endl, std::ifstream, std::istream;

/**
 * Convert a `MyString` object to `int`.
 * Works a lot like number slicing in reverse.
 * Just doing base 10 here.
 *
 * @param str the string to convert
 */
int mstoi(const MyString& str);

/**
 * Extract a `MyString` value from an input stream.
 *
 * @param is input stream
 * @param str MyString object into which to read the value (overwriting any existing data)
 * @returns the updates input stream after extraction
 */
istream& operator>>(istream& is, MyString& str);

int main() {
    // open command file
    MyString filename;  // uses the `MyString` default constructor
    cin >> filename;  // uses the provided `operator>>`

    // MyString: data() returns const char* type
    // (otherwise, have to implement ifstream constructor for MyString type)
    ifstream commands(filename.data());

    if (!commands.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    Rover testRover;

    // read commands
    MyString comm;
    MyString data;
    while (!commands.eof()) {
        commands >> comm;

        if (comm.front() == 'P') {  // uses `MyString::front`
            testRover.print();
            continue;
        }

        if (comm.front() == 'C') {
            testRover.clear();
            continue;
        }

        commands >> data;

        switch (comm.front()) {
            case 'S':
                testRover.set_smile(data);
                break;
            case 'R':
                testRover.read(mstoi(data));  // uses provided `mstoi`
                break;
            case 'J':
                testRover.join(data);
                break;
            case 'T':
                cout << testRover.test(data) << endl;
                break;
            case 'F':
                cout << data << " ";  // uses `MyString::operator<<`
                if (testRover.find(data)) {
                    cout << "was found" << endl;
                } else {
                    cout << "was not found" << endl;
                }
                break;
            default:
                continue;
        }
    }

    return 0;
}

int mstoi(const MyString& str) {
    int result = 0;
    for (unsigned int i = 0; i < str.size(); i++) {  // uses `MyString::size`
        if (str.at(i) >= '0' && str.at(i) <= '9') {  // uses `MyString::at`
            result *= 10;  // add a digit (reverse of number slicing)
            result += str.at(i) - '0';  // using ascii for conversion
        }
    }
    return result;
}

istream& operator>>(istream& is, MyString& str) {
    str.clear();
    while (!is.eof()) {
        char c;
        is >> std::noskipws >> c;  // don't skip whitespace
        if (isspace(c) || is.fail()) break;  // if whitespace, can stop adding to string
        const char* newstr = new char[2] {c, '\0'};  // make a c-string
        MyString newc = MyString(newstr);  // uses `MyString` copy constructor
        delete[] newstr;
        str += newc;  // uses `MyString::operator+=`
    }
    return is;
}
