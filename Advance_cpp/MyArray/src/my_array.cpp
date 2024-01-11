#include "my_array.h"


std::ostream& operator<<(std::ostream& os, const MyArray& a){
    os << '[' << a[0]; //int MyArray::operator[](int i) const
    for(int i =1; i<a.Size(); i++){
        os << ", " << a[i];
    }
    os << ']';
    return os; 
}

MyArray::MyArray(){
    for( int& v : data){
        v = 0;
    }
}

int MyArray::Size() const{
    return 5;
}

int& MyArray::operator[](int i){
    return data[i];
}

int MyArray::operator[](int i) const{
    return data[i];
}
