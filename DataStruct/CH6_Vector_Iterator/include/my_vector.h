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
        // TODO:
        // [] overload
        // at
        // size
        // empty
    private:
        T* p;
        int len;
};

#endif