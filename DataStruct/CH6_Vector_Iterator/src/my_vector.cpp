#include "my_vector.h"
#include <iostream>
template <typename T>
MyVector<T>::MyVector(int n){    
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

// template <typename T>
// void MyVector<T>::push_back(T data){
//     T *p_tmp = (T*) malloc(sizeof(T)*(len+1));
//     for(int i = 0; i<len; i++){
//         *(p_tmp+i) = *(p+i);
//     }
//     *(p_tmp+len) = data;
//     len++;
//     free(p);
//     p = p_tmp;
// }

template <typename T>
void MyVector<T>::pop_back(){
    //*(p+len) = 0; //does not need
    len--;    
}

// template <typename T>
// void MyVector<T>::pop_back(){
//     T *p_tmp = (T*) malloc(sizeof(T)*(len-1));
//     for(int i = 0; i<len-1; i++){
//         *(p_tmp+i) = *(p+i);
//     }
//     len--;
//     free(p);
//     p = p_tmp;
// }

template <typename T>
void MyVector<T>::insert(int index, T data){
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

// template <typename T>
// void MyVector<T>::insert(int index, T data){
//     T *p_tmp = (T*) malloc(sizeof(T)*(len+1));
//     for(int i = 0; i<len; i++){
//         if(i < index){
//             *(p_tmp+i) = *(p+i);
//         }
//         else if(i == index){
//             *(p_tmp+i) = data;
//         }
//         else{
//             *(p_tmp+i+1) = *(p+i);
//         }        
//     }
//     len++;
//     free(p);
//     p = p_tmp;
// }

template <typename T>
void MyVector<T>::erase(int index){
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

// template <typename T>
// void MyVector<T>::erase(int index){
//     if(is_empty()){
//         return;
//     }
//     if(index > size()-1){
//         return;
//     }
//     T *p_tmp = (T*) malloc(sizeof(T)*(len-1));
//     for(int i = 0; i<len; i++){
//         if(i < index){
//             *(p_tmp+i) = *(p+i);
//         }
//         else if(i == index){
//             continue;
//         }
//         else{
//             *(p_tmp+i-1) = *(p+i);
//         }        
//     }
//     len--;
//     free(p);
//     p = p_tmp;
// }

template <typename T>
void MyVector<T>::erase(int begin_index, int end_index){
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
    for(int i = 0; i<end_index-begin_index; i++){
        *(p+begin_index+i) = *(p+end_index+i);
    }
    len = len-(end_index-begin_index);
    
}

// template <typename T>
// void MyVector<T>::erase(int begin_index, int end_index){
//     if(is_empty()){
//         return;
//     }
//     if(begin_index<0){
//         return;
//     }
//     if(end_index>size()-1){
//         return;
//     }
//     if(end_index<=begin_index){
//         return;
//     }
//     T *p_tmp = (T*) malloc(sizeof(T)*(len-(end_index-begin_index)));
//     for(int i = 0; i<begin_index; i++){
//         *(p_tmp+i) = *(p+i);
//     }
//     for(int i = end_index; i<len; i++){
//         *(p_tmp+i-(end_index-begin_index)) = *(p+i);
//     }
//     len=len-(end_index-begin_index);
//     free(p);
//     p = p_tmp;
// }

template <typename T>
void MyVector<T>::clear(){
    free(p);
    //p = nullptr; //does not need
    len = 0;
    clear = 0;
}

template <typename T>
void MyVector<T>::resize(int n){
    if(n < 0){
        return;
    }
    if(n <= capacity){
        len = n;
    }
}

template <typename T>
void MyVector<T>::reserve(int n){
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