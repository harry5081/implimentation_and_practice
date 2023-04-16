#include "Rectangle.h"
#include<iostream>

void RECTANGLE::set_len(float w,float h){
    width = w;
    height = h;

}

float RECTANGLE::area(){

    return width*height;
}

void RECTANGLE::print(){
    std::cout << "width: "<< width << std::endl;
    std::cout << "height: "<< height << std::endl;

}