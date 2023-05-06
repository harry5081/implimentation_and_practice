#include <iostream>
#include "src/my_vector.cpp"


#define N 5 
int main(){

    int *p1 = new int[N];
    int *p2 = (int*) malloc(sizeof(int)*N);

    MyVector<int> myVector; 
    for(int i = 0; i<3; i++){
        myVector.push_back(i);
        std::cout<< myVector[i] <<std::endl;
    }
    std::cout<< myVector.size() <<std::endl;
    std::cout<< myVector.is_empty()<<std::endl;
    for(int i = 0; i<3; i++){
        myVector.pop_back();
    }
    std::cout<< myVector.is_empty()<<std::endl;
    
    return 0;
}