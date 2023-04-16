#ifndef COURSE_H
#define COURSE_H

#include <iostream>

namespace MY_CODE{

class COURSE{
    std::string teacher;
    int student_num = 3;
    int* grade;

    public:
        void set_teacher(std::string);
        std::string get_teacher();

        void set_grade(int*);
        int* get_grade();
        void print_grade();

        float average();


};

}

#endif