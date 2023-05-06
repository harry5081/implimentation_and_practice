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

template <typename T>
T& MyVector<T>::operator[](int index){
   return *(p + index);
}

template <typename T>
T& MyVector<T>::At(int index){
   return *(p + index);
}

template <typename T>
int MyVector<T>::size(){
   return len;
}

template <typename T>
bool MyVector<T>::is_empty(){
    return len == 0;
}

template <typename T>
void MyVector<T>::push_back(T data){
    T *p_tmp = (T*) malloc(sizeof(T)*(len+1));
    for(int i = 0; i<len; i++){
        *(p_tmp+i) = *(p+i);
    }
    *(p_tmp+len) = data;
    len++;
    free(p);
    p = p_tmp;
}

template <typename T>
void MyVector<T>::pop_back(){
    T *p_tmp = (T*) malloc(sizeof(T)*(len-1));
    for(int i = 0; i<len-1; i++){
        *(p_tmp+i) = *(p+i);
    }
    len--;
    free(p);
    p = p_tmp;
}