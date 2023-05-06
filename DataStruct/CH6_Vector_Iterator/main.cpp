#include <iostream>
#include "src/my_vector.cpp"


#define N 5 
int main(){

    int *p1 = new int[N];
    int *p2 = (int*) malloc(sizeof(int)*N);

    MyVector<int> myVector(10); 

    for(int i = 0; i<myVector.size(); i++){
        myVector[i] = i*10;
        std::cout<< myVector[i] << " ";
    }
    std::cout<<std::endl;
    
    myVector.insert(5,9); 
    for(int i = 0; i<myVector.size(); i++){
        std::cout<< myVector[i] << " ";
    }
    std::cout<<std::endl;

    myVector.erase(2,6); 
    for(int i = 0; i<myVector.size(); i++){
        std::cout<< myVector[i] << " ";
    }
    std::cout<<std::endl;

    // myVector.erase(3,5);
    // myVector.erase(6,8);
    // for(int i = 0; i<myVector.size(); i++){
    //     std::cout<< myVector[i] << " ";
    // }
    // std::cout<<std::endl;
    
    return 0;
}