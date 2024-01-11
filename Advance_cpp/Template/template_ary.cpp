#include <iostream>
#include <initializer_list>

template<typename T, int N>
class MyArray{
    public:
        MyArray();
        MyArray(std::initializer_list<T>);
        int Size() const;
        T& operator[](int i);
        T operator[](int i) const;
    private:
        T data[N];
};

template<typename T, int N>
std::ostream& operator<<(std::ostream& os, const MyArray<T, N>& a){
    os << '[' << a[0]; //int MyArray::operator[](int i) const
    for(int i =1; i<a.Size(); i++){
        os << ", " << a[i];
    }
    os << ']';
    return os; 
}

template<typename T, int N>
MyArray<T, N>::MyArray(){
    for( T& n : data){
        // n = 0;
        n = T();
    }
}

template<typename T, int N>
MyArray<T, N>::MyArray(std::initializer_list<T> l){
    int i = 0;
    for(T n:l){
        data[i] = n;
        i++;
    }
}

template<typename T, int N>
int MyArray<T, N>::Size() const{
    return N;
}

template<typename T, int N>
T& MyArray<T, N>::operator[](int i){
    return data[i];
}

template<typename T, int N>
T MyArray<T, N>::operator[](int i) const{
    return data[i];
}
template<typename T, int N>
T* begin(MyArray<T, N> &a){
    return &a[0];
}

template<typename T, int N>
T* end(MyArray<T, N> &a){
    return &a[N];
}

int main(){
    MyArray<float, 10> a;
    std::cout << a << std::endl;
    a[5] = 7;
    a[6] = 9;

    int v[5] = {10, 20, 30, 40, 50};
    for (int n : v){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (int* p = &v[0]; p != &v[5]; p++){
        int n = *p;
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (auto p = std::begin(v); p != std::end(v); p++){
        int n = *p;
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (auto p = begin(a); p != end(a); p++){
        int n = *p;
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (auto n : a){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::initializer_list<int> l ={101, 102, 103};
    MyArray<float, 10> b = {100, 200, 300};
    std::cout << b << std::endl;


    return 0;
}
