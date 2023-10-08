// #include <stdio.h>
#include "src/stack.cpp"

int main(){
    Stack<int> my_stack(1);
    Stack<int> my_stack2(5);
    my_stack.Print_Stack();
    my_stack2.Print_Stack();

    for(int i=0;i<10;i++){
        my_stack.Push(i*i);
        my_stack.Print_Stack();
    }

    for(int i=0;i<10;i++){
        my_stack.Pop();
        my_stack.Print_Stack();
    }
    
    return 0;
}