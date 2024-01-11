#include "my_cout.h"


void operator<<(std::ostream& os, int (&v)[5]){
    os << '[' << v[0];
    for(int i =1; i<5; i++){
        os << ", " << v[i];
    }
    os << ']';
}


OutputStream myCout;

OutputStream& OutputStream::operator<<(const char* str){
    printf("%s", str);
    return *this;
}

OutputStream& OutputStream::operator<<(int val){
    printf("%d", val);
    return *this;
}



// OutputStream OutputStream::operator<<(const char* str){
//     printf("%s", str);
//     return OutputStream();
// }

// OutputStream OutputStream::operator<<(int val){
//     printf("%d", val);
//     return OutputStream();
// }