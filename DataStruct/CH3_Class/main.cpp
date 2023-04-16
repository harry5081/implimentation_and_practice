#include<iostream>
#include "Rectangle.h"
#include "Course.h" 

namespace CODE_VERSION{
    //#include "Course.h" 
    #include "Course_v2.h" 
    #include "Course_v3.h" 
}


int main(){

    RECTANGLE r1;
    r1.set_len(5,10);
    std::cout << r1.area() << std::endl;

    RECTANGLE* r2 = &r1;
    std::cout << r2->area() << std::endl;
    r2->print();

    RECTANGLE* r3 = new RECTANGLE;

    MY_CODE::COURSE math;
    math.set_teacher("Harry");
    std::cout << math.get_teacher() << std::endl;

    int grade_temp[]={50,60,100};
    math.set_grade(grade_temp);

    math.print_grade();
    int*temp = math.get_grade();

    for(int i=0;i<3;i++){
        std::cout<<*(temp+i)<<" ";
    }
    std::cout<<std::endl;
    std::cout<<math.average()<<std::endl;

    CODE_VERSION::COURSE geo;
    std::cout << geo.get_teacher() << std::endl;
    

    return 0;
}