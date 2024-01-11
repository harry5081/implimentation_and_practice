#include <iostream>


template<typename T>
class Point{
    public:
        T x;
        T y;
};
template<typename T>
std::ostream& operator<<(std::ostream&, const Point<T>&);

int main(){
    Point<int> p = {3, 5};
    Point<double> q = {3.2, 5.4};
    std::cout << "p: " << p << std::endl
              << "q: " << q << std::endl;
    return 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p){
    os << "("<< p.x << ", " << p.y << ")";
    return os;
}