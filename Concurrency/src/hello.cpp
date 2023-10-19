#include <iostream>
#include <thread>
#include <functional>

#define NUM_THREADS 10

// g++ ../src/hello.cpp -lpthread -o hello

void Hello(){
    // std::cout << "Hello, Concurrent World!\n" << std::endl;
    std::cout << "Hello, Concurrent World!\n";
}

void Clear(int &data){
    data = 0;
}

int main(){
    std::cout << "This is main Thread!" << std::endl;
    
    // one thread
    std::thread t(Hello);
    t.join();

    // multiple threads
    std::thread t_arr[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++){
        t_arr[i] = std::thread(Hello);
    }

    for(int i = 0; i < NUM_THREADS; i++){
        t_arr[i].join();
    }

    // send callable with argument, and call by reference
    int data = 10;
    std::thread t_reference(Clear, std::ref(data));
    t_reference.join();
    std::cout << "data:" << data << std::endl;
    
}