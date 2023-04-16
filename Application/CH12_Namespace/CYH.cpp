#include <iostream>
#include "CYH.h"


// int CYH_OUT::begin_cnt = 5;

// void CYH_OUT::print(){

//     std::cout<< "This is namespace CYH_OUT"<<std::endl;

// }

namespace CYH_OUT{

    namespace{
        float out_xxx =  5.9;
    }

    int begin_cnt = 5;
    void print(){
        std::cout<< "begin_cnt in namespace CYH_OUT: " << begin_cnt <<std::endl;
        std::cout<< "This is namespace CYH_OUT"<<std::endl;
    }

}