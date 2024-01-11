# ifndef MY_COUT
# define MY_COUT

#include <stdio.h>
#include <ostream>

void operator<<(std::ostream& os, int(&) [5]);

class OutputStream{
    public:
        OutputStream& operator<<(const char* str);
        OutputStream& operator<<(const int val);
        // OutputStream operator<<(const char* str);
        // OutputStream operator<<(const int val);
};

// global object instance
// https://stackoverflow.com/questions/297822/global-instance-of-a-class-in-c
extern OutputStream myCout;

# endif