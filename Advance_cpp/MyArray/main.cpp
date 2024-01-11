#include "my_array.h"
#include <iostream>
int main(){
    MyArray a;
    a[2] = 7; //int& MyArray::operator[](int i)
    std::cout << a << std::endl;

    MyArray b = a;
    std::cout << b;
    
}