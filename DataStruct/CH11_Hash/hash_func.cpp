#include <iostream>
#include <math.h>

int Hash_Function_Div(std::string input, int m){

    long long int sum = 0;

    for (int i = 0; i < input.length(); i++){
        sum += (int)input[i];
    }

    return sum % m;

} 

int Hash_Function_Multiplication(std::string input, int m){

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
    int index = m * frac;
    return index;
} 


