#include "my_vector_itr.h"
#include <iostream>
template <typename T>
VectorItr::MyVector<T>::MyVector(int n){    
    if(n == 0){
        p = nullptr;
        len = n;
        capacity = 0;
    }
    else{
        // p = (T*) malloc(sizeof(T) * n);
        p = (T*)calloc(n, sizeof(T));
        len = n;
        capacity = n;   
    }
    
}

template <typename T>
VectorItr::MyVector<T>::~MyVector(){
    free(p);
}

template <typename T>
T VectorItr::MyVector<T>::Front(){
   return *p;
}

template <typename T>
T VectorItr::MyVector<T>::Back(){
   return *(p + len - 1);
}

template <typename T>
T& VectorItr::MyVector<T>::operator[](int index){
   return *(p + index);
}

template <typename T>
T& VectorItr::MyVector<T>::At(int index){
   return *(p + index);
}

template <typename T>
int VectorItr::MyVector<T>::size(){
   return len;
}

template <typename T>
bool VectorItr::MyVector<T>::is_empty(){
    return len == 0;
}

template <typename T>
void VectorItr::MyVector<T>::push_back(T data){
    if(len == capacity){
        if(capacity == 0){
            reserve(1);
        }
        else{
            reserve(capacity*2);   
        }             
    }
    *(p+len) = data;
    len++;
}

template <typename T>
void VectorItr::MyVector<T>::pop_back(){
    //*(p+len) = 0; //does not need
    len--;    
}

template <typename T>
void VectorItr::MyVector<T>::insert(int index, T data){
    if(index > size()-1){
        return;
    }
    if(index < 0){
        return;
    }
    if(len == capacity){
        if(capacity == 0){
            reserve(1);
        }
        else{
            reserve(capacity*2);   
        }             
    }
        
    for(int i = len-1; i>=index; i--){
        *(p+i+1) = *(p+i);
    }    
    *(p+index) = data;
    len++;
}

template <typename T>
void VectorItr::MyVector<T>::erase(int index){
    if(is_empty()){
        return;
    }
    if(index > size()-1){
        return;
    }
    for(int i = index; i<len; i++){
        *(p+i) = *(p+i+1);
    }
    len--;
}

template <typename T>
void VectorItr::MyVector<T>::erase(int begin_index, int end_index){
    if(is_empty()){
        return;
    }
    if(begin_index<0){
        return;
    }
    if(end_index>size()-1){
        return;
    }
    if(end_index<=begin_index){
        return;
    }
    for(int i = 0; i<end_index-begin_index+1; i++){
        *(p+begin_index+i) = *(p+end_index+i);
    }
    len = len-(end_index-begin_index);
    
}

template <typename T>
void VectorItr::MyVector<T>::clear(){
    //free(p); // will cause "double free detected in tcache 2" problem
    //p = nullptr; //does not need
    len = 0;
    capacity = 0;
}

template <typename T>
void VectorItr::MyVector<T>::resize(int n){
    if(n < 0){
        return;
    }
    if(n <= capacity){
        len = n;
    }
}

template <typename T>
void VectorItr::MyVector<T>::reserve(int n){
    if(n < len){
        return;
    }
    capacity = n;
    T *p_tmp = (T*) malloc(sizeof(T)*capacity);
    for(int i = 0; i < len; i++){
        *(p_tmp+i) = *(p+i);
    }
    free(p);
    p = p_tmp;
}

template <typename T>
VectorItr::MyVector<T>::Iterator::Iterator(T* ptr){
    itr = ptr;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator++(){
    itr++;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator--(){
    itr--;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator++(int){
    itr++;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator--(int){
    itr--;
}

//10:59