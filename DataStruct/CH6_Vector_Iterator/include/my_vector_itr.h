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

        void insert(int index, T data);
        void erase(int index);
        void erase(int begin_index, int end_index);
        void clear();

        void resize(int n);
        void reserve(int n);

    private:
        T* p;
        int len;
        int capacity;
};

#endif