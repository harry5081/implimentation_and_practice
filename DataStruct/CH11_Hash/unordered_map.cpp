#include <iostream>
#include <math.h>

template<typename T1, typename T2>
class UNORDERED_MAP{
    private:
        int len;
        int Hash_Function_Div(T1 input);
        int Hash_Function_Multiplication(T1 input);

    public:



};

template<typename T1, typename T2>
int UNORDERED_MAP<T1,T2>::Hash_Function_Div(T1 input){

    long long int sum = 0;

    for (int i = 0; i < input.length(); i++){
        sum += (int)input[i];
    }

    return sum % len;

} 

template<typename T1, typename T2>
int UNORDERED_MAP<T1,T2>::Hash_Function_Multiplication(T1 input){

    long long int sum = 0;
    int tmp = 1;

    for (int i = 0; i < input.length(); i++){
        sum += ((int)input[i])*tmp;
        tmp *= 256;
    }

    long long int key = sum;

    double c = (sqrt(5)-1)/2.0;

    double multi = key * c;
    double frac = multi - int(multi);
    int index = len * frac;
    return index;
} 

