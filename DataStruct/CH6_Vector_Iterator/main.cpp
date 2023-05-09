#include <iostream>
#include "src/my_vector.cpp"
#include "src/Vector_solution.h"

#include "src/my_vector_itr.cpp"


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
    std::cout<<myVector.size()<<std::endl;
    
    myVector.insert(5,9); 
    for(int i = 0; i<myVector.size(); i++){
        std::cout<< myVector[i] << " ";
    }
    std::cout<<std::endl;
    std::cout<<myVector.size()<<std::endl;

    myVector.erase(2,6); 
    for(int i = 0; i<myVector.size(); i++){
        std::cout<< myVector[i] << " ";
    }
    std::cout<<std::endl;
    std::cout<<myVector.size()<<std::endl;

    myVector.clear();
    myVector.push_back(5);
    myVector.push_back(4);
    myVector.push_back(3);
    myVector.push_back(2);
    myVector.push_back(1);
    myVector.insert(3,1000);
    myVector.erase(0,3);

    for(int i = 0; i<myVector.size(); i++){
        std::cout<< myVector[i] << " ";
    }
    std::cout<<std::endl;

    VectorItr::MyVector<int> myVectorItr;
    myVectorItr.clear();
    myVectorItr.push_back(5);
    myVectorItr.push_back(4);
    myVectorItr.push_back(3);

    for(int i = 0; i<myVectorItr.size(); i++){
        std::cout<< myVectorItr[i] << " ";
    }
    std::cout<<std::endl;


    VectorItr::MyVector<int>::Iterator itr(&myVector[0]);

    
    
    return 0;
}