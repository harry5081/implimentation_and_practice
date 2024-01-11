#include "my_grade.h"


std::ostream& operator<<(std::ostream& os, const MyGrade& g){
    os << g.value;
    return os;    
}

MyGrade::MyGrade(){
    value = 0;
}

MyGrade::MyGrade(int v){
    if(v > 100){
        v = 100;
    } else if( v < 0){
        v = 0;
    }
    value = v;
}

const MyGrade operator+(const MyGrade& g1, const MyGrade& g2){
    return g1.value + g2.value;
}

// const MyGrade MyGrade::operator+(const MyGrade& rhs) const{
//     return value + rhs.value;
// }