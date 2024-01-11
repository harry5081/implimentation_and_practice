#include "my_cout.h"
#include <iostream>
int main(){
    myCout<<"3+5 ==";
    myCout<<3+5;
    myCout<<"\n";
    myCout<<"3+5 =="<<3+5<<"\n";
    
    int a[5] = {1,2,3};
    
    std::cout<<a;
    
}