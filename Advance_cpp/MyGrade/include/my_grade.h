# ifndef MY_GRADE
# define MY_GRADE

#include <stdio.h>
#include <ostream>

class MyGrade{
        friend std::ostream& operator<<(std::ostream& os, const MyGrade& g);
        friend const MyGrade operator+(const MyGrade& g1, const MyGrade& g2);
    public:
        MyGrade();
        MyGrade(int v);
        // const MyGrade operator+(const MyGrade& rhs) const;  // the third const means that this member function can be call by a const instance
    private:
        int value;
};

std::ostream& operator<<(std::ostream& os, const MyGrade& g);
const MyGrade operator+(const MyGrade& g1, const MyGrade& g2);




# endif