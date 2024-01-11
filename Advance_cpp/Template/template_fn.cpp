#include <iostream>

template<int V>
void Assign(int&);

int main(){
    int a = 0, b = 0;
    Assign<3>(a);
    Assign<5>(b);
    std::cout << "a: "<< a << std::endl
              << "b: "<< b << std::endl;
    return 0;
}

template<int V>
void Assign(int& o){
    o = V;
}