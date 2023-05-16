#ifndef MY_VECTOR_ITR
#define MY_VECTOR_ITR
 
#include <stdlib.h>
#include <vector>

namespace VectorItr{

template <typename T>
class MyVector{
    public:
        class Iterator{
            private:
                T* ptr;
            public:
                Iterator(T* = nullptr);                

                void operator++(); // ++Iterator
                void operator--(); // --Iterator

                void operator++(int); // Iterator++
                void operator--(int); // Iterator--

                bool operator==(Iterator&); //faster by passing reference
                bool operator!=(Iterator); // call by reference does not work
                                            // why?

                void operator=(Iterator);
                bool operator>(Iterator);
                bool operator>=(Iterator);
                bool operator<(Iterator);
                bool operator<=(Iterator);
                Iterator operator+(int);
                Iterator operator-(int);
                int operator-(Iterator);

                T& operator*();
        };        

        MyVector(int n = 0);
        ~MyVector();

        Iterator begin();
        Iterator end();

        T Front();
        T Back();

        // return reference(left value, accept assign operation)
        T& At(int index);            
        T& operator[](int index);        
        int size();
        bool is_empty();
        
        void push_back(T data);
        void pop_back();

        void insert(Iterator& itr, T data);
        void erase(Iterator& itr);
        void erase(Iterator begin_itr, Iterator end_itr);
        void clear();

        void resize(int n);
        void reserve(int n);        

    private:
        T* p;
        int len;
        int capacity;
};

};

#endif