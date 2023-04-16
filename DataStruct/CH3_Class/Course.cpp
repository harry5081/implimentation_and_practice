#include "Course.h"

inline namespace MY_CODE{

void COURSE::set_teacher(std::string name){
    teacher = name;

}

std::string COURSE::get_teacher(){
    return teacher;

}

void COURSE::set_grade(int* grade_arr){
    grade = grade_arr;

}

void COURSE::print_grade(){
    int* temp;
    temp = grade;
    for(int i = 0;i<student_num;i++){
        std::cout<< *temp << " ";
        temp++;
    }
    std::cout<<std::endl;

}

int* COURSE::get_grade(){
    return grade;

}

float COURSE::average(){
    float sum = 0;
    for(int i=0;i<student_num;i++){
        sum = sum + *(grade+i);
    }
    sum /= student_num;
    return sum;

}

}