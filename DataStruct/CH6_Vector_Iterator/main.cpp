#include <iostream>
#include "src/my_vector.cpp"


#define N 5 
int main(){

    int *p1 = new int[N];
    int *p2 = (int*) malloc(sizeof(int)*N);

    MyVector<int> myVector(5); 
    std::cout<< myVector.Front() <<std::endl;
    std::cout<< myVector.Back() <<std::endl;

    return 0;
}