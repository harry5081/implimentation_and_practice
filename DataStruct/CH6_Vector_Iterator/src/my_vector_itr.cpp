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
typename VectorItr::MyVector<T>::Iterator VectorItr::MyVector<T>::begin(){
   Iterator itr_tmp(p);
   return itr_tmp;
}

template <typename T>
typename VectorItr::MyVector<T>::Iterator VectorItr::MyVector<T>::end(){
   Iterator itr_tmp(p+size());
   return itr_tmp;
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
void VectorItr::MyVector<T>::insert(Iterator& itr2, T data){
    if(itr2 >= end()){
        return;
    }
    if(itr2 < begin()){
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

    // auto tmp = itr2;
    // for(itr2 = end();itr2>=tmp;itr2--){
    //     *(itr2+1)=*(itr2);
    // }

    
    for(Iterator itr_tmp(end()); itr_tmp>itr2; itr_tmp--){
        *(itr_tmp) = *(itr_tmp-1);
    }
    *itr2 = data;
    len++;
}

template <typename T>
void VectorItr::MyVector<T>::erase(Iterator& itr2){
    if(is_empty()){
        return;
    }
    if(itr2 >= end()){
        return;
    }
    if(itr2 < begin()){
        return;
    }
    for(Iterator i(itr2); i<end(); i++){
        *(i) = *(i+1);
    }
    len--;
}

template <typename T>
void VectorItr::MyVector<T>::erase(Iterator begin_itr, Iterator end_itr){
    if(is_empty()){
        return;
    }
    if(begin_itr<begin()){
        return;
    }
    if(end_itr>=end()){
        return;
    }
    if(end_itr<=begin_itr){
        return;
    }
    for(int i = 0; i<end_itr-begin_itr+1; i++){
        *(begin_itr+i) = *(end_itr+i);
    }
    len = len-(end_itr-begin_itr);
    
}

template <typename T>
void VectorItr::MyVector<T>::clear(){
    //free(p); // will cause "double free detected in tcache 2" problem
    len = 0;
    capacity = 0;
    p = nullptr;
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
VectorItr::MyVector<T>::Iterator::Iterator(T* ptr2){
    ptr = ptr2;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator++(){
    ptr++;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator--(){
    ptr--;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator++(int){
    ptr++;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator--(int){
    ptr--;
}

template <typename T>
bool VectorItr::MyVector<T>::Iterator::operator==(Iterator& itr2){
    return ptr == itr2.ptr;
}

template <typename T>
bool VectorItr::MyVector<T>::Iterator::operator!=(Iterator itr2){
    return ptr != itr2.ptr;
}

template <typename T>
void VectorItr::MyVector<T>::Iterator::operator=(Iterator itr2){
    ptr = itr2.ptr;
}

template <typename T>
bool VectorItr::MyVector<T>::Iterator::operator>(Iterator itr2){
    return ptr > itr2.ptr;
}

template <typename T>
bool VectorItr::MyVector<T>::Iterator::operator>=(Iterator itr2){
    return ptr >= itr2.ptr;
}

template <typename T>
bool VectorItr::MyVector<T>::Iterator::operator<(Iterator itr2){
    return ptr < itr2.ptr;
}

template <typename T>
bool VectorItr::MyVector<T>::Iterator::operator<=(Iterator itr2){
    return ptr <= itr2.ptr;
}

template <typename T>
T& VectorItr::MyVector<T>::Iterator::operator*(){
    return *ptr;
}

template <typename T>
typename VectorItr::MyVector<T>::Iterator VectorItr::MyVector<T>::Iterator::operator+(int n){
    Iterator itr_tmp(ptr + n);
    return itr_tmp;
}

template <typename T>
typename VectorItr::MyVector<T>::Iterator VectorItr::MyVector<T>::Iterator::operator-(int n){
    Iterator itr_tmp(ptr - n);
    return itr_tmp;
}
template <typename T>
int VectorItr::MyVector<T>::Iterator::operator-(Iterator itr2){
    return (ptr - itr2.ptr);
}
//25:35