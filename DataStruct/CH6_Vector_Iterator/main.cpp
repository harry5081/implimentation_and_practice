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
    
    // Iterator
    VectorItr::MyVector<int> myVector2;
    myVector2.clear();
    myVector2.push_back(5);
    myVector2.push_back(4);
    myVector2.push_back(3);
    myVector2.push_back(909);
    myVector2.push_back(808);
    myVector2.push_back(707);
    myVector2.push_back(606);


    for(int i = 0; i<myVector2.size(); i++){
        std::cout<< myVector2[i] << " ";
    }
    std::cout<<std::endl;


    VectorItr::MyVector<int>::Iterator itr(&myVector2[0]);
    for(int i =0;i<myVector2.size();i++){
        std::cout << *itr << " ";
        itr++;
    }
    std::cout<<std::endl;

    VectorItr::MyVector<int>::Iterator itr3(&myVector2[myVector2.size()]);

    if(itr3 == itr){
        std::cout << "Same"<<std::endl;
    }

    if(itr3 != itr){
        std::cout << "Different"<<std::endl;
    }

    std::cout<<*(myVector2.begin())<<std::endl;
    std::cout<<*(myVector2.end())<<std::endl;

    VectorItr::MyVector<int>::Iterator itr_insert;
    itr_insert = &myVector2[1];
    myVector2.insert(itr_insert,876);

    for(VectorItr::MyVector<int>::Iterator itr=myVector2.begin(); itr != myVector2.end(); ++itr){
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    VectorItr::MyVector<int>::Iterator itr_erase;
    itr_erase = myVector2.begin();
    myVector2.erase(itr_erase);

    for(VectorItr::MyVector<int>::Iterator itr=myVector2.begin(); itr != myVector2.end(); ++itr){
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    VectorItr::MyVector<int>::Iterator itr_erase_begin(&myVector2[3]);
    VectorItr::MyVector<int>::Iterator itr_erase_end(&myVector2[5]);
   

    myVector2.erase(itr_erase_begin,itr_erase_end);
    
    // myVector2.insert(&myVector2[1],666);
    for(VectorItr::MyVector<int>::Iterator itr=myVector2.begin(); itr != myVector2.end(); ++itr){
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
    
    
    
    return 0;
}