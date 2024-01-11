#include <iostream>
#include <string>

int main(){
    std::string s = "Hello";
    std::cout << "s: "<< s << std::endl
              << "s.size(): "<< s.size() << std::endl
              << "s[3]: "<< s[3] << std::endl;

    std::cout << *s.begin() << " " << *begin(s) << std::endl;
    
    for(auto p = s.begin(); p != s.end(); ++p){
        std::cout << *p;
    }
    std::cout << std::endl;

    return 0;
}
