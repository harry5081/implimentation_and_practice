#include <iostream>
#include "hash_func.cpp"
#include "unordered_map.cpp"

int main(){

    std::string str;
    
    std::cout<< "Please enter a string: "<<std::endl;
    std::cin >>str;

   std::cout<< "KEY: " << Hash_Function_Div(str, 8) << std::endl; ;
   std::cout<< "KEY: " << Hash_Function_Multiplication(str, 8) << std::endl; ;

   UNORDERED_MAP<std::string,int> balance; 


    return 0;
}