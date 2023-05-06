#ifndef MY_VECTOR
#define MY_VECTOR
 
#include <stdlib.h> 

template <typename T>
class MyVector{
    public:
        MyVector(int n = 0);
        ~MyVector();
        T Front();
        T Back();

        // return reference(left value, accept assign operation)
        T& At(int index);            
        T& operator[](int index);        
        int size();
        bool is_empty();
        
        void push_back(T data);
        void pop_back();

        //TODO:
        // insert(int index)
        // erase(int index)
        // erase(int begin_index, int end_index)
        // clear()
    private:
        T* p;
        int len;
};

#endif