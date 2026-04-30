// TODO(student): Define the MyString class methods
#include "MyString.h"

const size_t MyString::npos=static_cast<size_t>(-1);

size_t MyString::cstring_length(const char* str){
    if(str==nullptr){
        return 0;
    }
    size_t len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}

void MyString::allocate_empty(){
    data_=new char[1];
    data_[0]='\0';
    size_=0;
    capacity_=1;
}

MyString::MyString():data_(nullptr),size_(0),capacity_(0){
    allocate_empty();
}

MyString::MyString(const MyString& other):data_(nullptr),size_(0),capacity_(0){
    size_=other.size_;
    capacity_=other.capacity_;
    data_=new char[capacity_];
    for(size_t i=0;i<=size_;i++){
        data_[i]=other.data_[i];
    }
}

MyString::MyString(const char* str):data_(nullptr),size_(0),capacity_(0){
    size_=cstring_length(str);
    capacity_=size_+1;
    data_=new char[capacity_];
    for(size_t i=0;i<size_;i++){
        data_[i]=str[i];
    }
    data_[size_]='\0';
}

MyString::~MyString(){
    delete[] data_;
}

MyString& MyString::operator=(const MyString& other){
    if(this!=&other){
        char* new_data=new char[other.capacity_];
        for(size_t i=0;i<=other.size_;i++){
            new_data[i]=other.data_[i];
        }
        delete[] data_;
        data_=new_data;
        size_=other.size_;
        capacity_=other.capacity_;
    }
    return *this;
}

MyString& MyString::operator+=(const MyString& other){
    size_t new_size=size_+other.size_;
    size_t new_capacity=new_size+1;
    char* new_data=new char[new_capacity];
    for(size_t i=0;i<size_;i++){
        new_data[i]=data_[i];
    }
    for(size_t i=0;i<other.size_;i++){
        new_data[size_+i]=other.data_[i];
    }
    new_data[new_size]='\0';
    delete[] data_;
    data_=new_data;
    size_=new_size;
    capacity_=new_capacity;
    return *this;
}

size_t MyString::size()const{
    return size_;
}

size_t MyString::length()const{
    return size_;
}

void MyString::resize(size_t n){
    if(n+1<=capacity_){
        if(n>size_){
            for(size_t i=size_;i<n;i++){
                data_[i]='\0';
            }
        }
        size_=n;
        data_[size_]='\0';
        return;
    }
    char* new_data=new char[n+1];
    size_t limit=size_<n?size_:n;
    for(size_t i=0;i<limit;i++){
        new_data[i]=data_[i];
    }
    for(size_t i=limit;i<n;i++){
        new_data[i]='\0';
    }
    new_data[n]='\0';
    delete[] data_;
    data_=new_data;
    size_=n;
    capacity_=n+1;
}

size_t MyString::capacity()const{
    return capacity_;
}

void MyString::clear(){
    size_=0;
    data_[0]='\0';
}

bool MyString::empty()const{
    return size_==0;
}

const char& MyString::at(size_t pos)const{
    if(pos>=size_){
        throw std::out_of_range("MyString::at out of range");
    }
    return data_[pos];
}

const char& MyString::front()const{
    return data_[0];
}

const char* MyString::data()const{
    return data_;
}

size_t MyString::find(const MyString& str,size_t pos)const{
    if(pos>size_){
        return npos;
    }
    if(str.size_==0){
        return pos;
    }
    if(str.size_>size_||pos+str.size_>size_){
        return npos;
    }
    for(size_t i=pos;i+str.size_<=size_;i++){
        bool match=true;
        for(size_t j=0;j<str.size_;j++){
            if(data_[i+j]!=str.data_[j]){
                match=false;
                break;
            }
        }
        if(match){
            return i;
        }
    }
    return npos;
}

std::ostream& operator<<(std::ostream& os,const MyString& str){
    for(size_t i=0;i<str.size();i++){
        os<<str.at(i);
    }
    return os;
}

MyString operator+(const MyString& lhs,const MyString& rhs){
    MyString result(lhs);
    result+=rhs;
    return result;
}

bool operator==(const MyString& lhs,const MyString& rhs){
    if(lhs.size()!=rhs.size()){
        return false;
    }
    for(size_t i=0;i<lhs.size();i++){
        if(lhs.at(i)!=rhs.at(i)){
            return false;
        }
    }
    return true;
}
