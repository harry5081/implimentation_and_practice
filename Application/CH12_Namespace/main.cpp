#include <iostream>
#include "CYH.h"

namespace CYH_IN{
    
    #include "namespace_v1.h"
    #include "namespace_v2.h"
    
    int begin_cnt = 0;

    void print(){
        std::cout<< "This is namespace CYH_IN"<<std::endl;
    }

    namespace{
        int xxx =  9;
    }

}

namespace{
        float xxx =  9.9;
} // namespace replaces static

int main(){

    //extern int a;

    std::cout<< CYH_IN::name_xxx <<std::endl; // namespace + inline

    std::cout<< CYH_IN::begin_cnt <<std::endl;
    CYH_IN::print();
    std::cout<< CYH_IN::xxx <<std::endl;
    std::cout<< xxx <<std::endl;

    std::cout<< CYH_OUT::begin_cnt <<std::endl;
    CYH_OUT::print();
    //std::cout<< CYH_OUT::out_xxx <<std::endl; // not valid
    
    return 0;
}