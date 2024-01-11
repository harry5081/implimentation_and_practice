#include <iostream>
#include <vector>

int main(){

    std::vector<int> a = {0, 1, 2, 3, 4, 5};
    
    for(size_t i = 0; i < a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> a_empty;
    a_empty.resize(3);
    a_empty.push_back(10);

    for(auto p = a_empty.begin(); p != a_empty.end(); p++){
        std::cout << *p << " ";
    }
    std::cout << std::endl;

    a_empty.insert(a_empty.begin()+1,4);
    for(auto v:a_empty){
        std::cout << v << " ";
    }
    std::cout << std::endl;

    a_empty.erase(a_empty.begin()+2);
    for(auto v:a_empty){
        std::cout << v << " ";
    }
    std::cout << std::endl;



    return 0;
}
