# ifndef MY_ARRAY
# define MY_ARRAY

#include <stdio.h>
#include <ostream>

class MyArray{
    public:
        MyArray();
        int Size() const;
        int& operator[](int i);
        int operator[](int i) const;
    private:
        int data[5];
};

std::ostream& operator<<(std::ostream& os, const MyArray& g);




# endif