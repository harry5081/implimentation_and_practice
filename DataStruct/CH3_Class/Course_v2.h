#ifndef COURSE_V2_H
#define COURSE_V2_H

#include <iostream>

namespace MY_CODE_V2{

class COURSE{
    
    public:
        std::string teacher = "Jerry";
        void set_teacher(std::string);

        std::string get_teacher()
        {
            return teacher;
        }


        void set_grade(int*);
        int* get_grade();

        float average();


};



}

#endif