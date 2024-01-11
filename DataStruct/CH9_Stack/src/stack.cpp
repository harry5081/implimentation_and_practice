#include "stack.h"
#include <iostream>
#include <stdlib.h>

template<typename T>
Stack<T>::Stack(int len){
    Capacity = len;
    if(len>0){
        Pointer = (T*) malloc(sizeof(T)*len);
    }
    else{
        Pointer = nullptr;
    }
    Top_Index = -1;
}

template<typename T>
void Stack<T>::Print_Stack(){
    if(Pointer == nullptr){
        std::cout << "The stack is empty" << std::endl;
        return;
    }

    for(int i = 0; i < Top_Index; i++){
        std::cout << *(Pointer+i) << " ";
    }
    std::cout << std::endl;
    return;
}

template<typename T>
T Stack<T>::Top(){
    if(!Empty){
        return Pointer[Top_Index];
    }
    return -1;
}

template<typename T>
bool Stack<T>::Empty(){
    return (Top_Index==-1);
}

template<typename T>
int Stack<T>::Size(){
    return Top_Index+1;
}

template<typename T>
void Stack<T>::Push(T data){
    if(Capacity == Top_Index-1){
        Double_Capacity();
    }
    Top_Index++;
    Pointer[Top_Index] = data;
    // or Pointer[++Top_Index] = data;
}

template<typename T>
void Stack<T>::Pop(){
    if(Empty()){
        return;
    }
    Top_Index--;
}

template<typename T>
void Stack<T>::Double_Capacity(){
    if(Capacity == 0){
        Capacity = 1;
        Pointer = (T*) malloc(sizeof(T));
    }
    else{
        Capacity *= 2;
        T* tmp = Pointer;
        Pointer = (T*) malloc(sizeof(T)*Capacity);
        for(int i = 0; i <= Top_Index; i++){
            Pointer[i] = tmp[i];
        }
        free(tmp);
    }
}





