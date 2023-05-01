#include "my_vector.h"

template <typename T>
MyVector<T>::MyVector(int n){    
    if(n == 0){
        p = nullptr;
        len = n;
    }
    else{
        // p = (T*) malloc(sizeof(T) * n);
        p = (T*)calloc(n, sizeof(T));
        len = n;
        
    } 
}

template <typename T>
MyVector<T>::~MyVector(){
   free(p);
}

template <typename T>
T MyVector<T>::Front(){
   return *p;
}

template <typename T>
T MyVector<T>::Back(){
   return *(p + len - 1);
}