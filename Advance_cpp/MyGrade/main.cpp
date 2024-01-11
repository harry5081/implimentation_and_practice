#include "my_grade.h"
#include <iostream>
int main(){
    MyGrade g(37);
    std::cout<<"MyGrade: "<< g << std::endl;

    MyGrade g1 = 37, g2 = 23;
    std::cout<<"MyGrade: "<< g1+g2 << std::endl;

    std::cout<<"MyGrade: "<< g1+30 << std::endl;
    std::cout<<"MyGrade: "<< 7+g1 << std::endl;
    std::cout<<"MyGrade: "<< 90+g1 << std::endl;

    MyGrade g3 = 120;
    
}