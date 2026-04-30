// TODO(student): Declare the MyString class
#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <iostream>
#include <stdexcept>

class MyString {
 private:
    char* data_;
    size_t size_;
    size_t capacity_;
    static size_t cstring_length(const char* str);
    void allocate_empty();
 public:
    static const size_t npos;
    MyString();
    MyString(const MyString& other);
    MyString(const char* str);
    ~MyString();
    MyString& operator=(const MyString& other);
    MyString& operator+=(const MyString& other);
    size_t size()const;
    size_t length()const;
    void resize(size_t n);
    size_t capacity()const;
    void clear();
    bool empty()const;
    const char& at(size_t pos)const;
    const char& front()const;
    const char* data()const;
    size_t find(const MyString& str,size_t pos=0)const;
};

std::ostream& operator<<(std::ostream& os,const MyString& str);
MyString operator+(const MyString& lhs,const MyString& rhs);
bool operator==(const MyString& lhs,const MyString& rhs);

#endif
