#ifndef COURSE_V3_H
#define COURSE_V3_H

#include <iostream>

inline namespace MY_CODE_V3{

class COURSE{
    
    public:
        std::string teacher = "David";
        void set_teacher(std::string);
        std::string get_teacher();

        void set_grade(int*);
        int* get_grade();

        float average();


};
} //MY_CODE_V3

std::string MY_CODE_V3::COURSE::get_teacher(){
    return teacher;

}


#endif