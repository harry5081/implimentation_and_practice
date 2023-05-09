#ifndef MY_VECTOR_ITR
#define MY_VECTOR_ITR
 
#include <stdlib.h> 

namespace VectorItr{

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

        class   Iterator{
            private:
                T* itr;
            public:
                Iterator(T* = nullptr);
                void operator++(); // ++Iterator
                void operator--(); // --Iterator

                void operator++(int); // Iterator++
                void operator--(int); // Iterator--

                bool operator==(Iterator&); //faster by passing reference
                bool operator!=(Iterator&);

                void operator=(Iterator&);

                T operator*();
        };

    private:
        T* p;
        int len;
        int capacity;
};

};

#endif