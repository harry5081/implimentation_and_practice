#include <iostream>
#include <thread>

#define NUM_THREADS 10

// g++ ../src/hello.cpp -lpthread -o hello

void Hello(){
    // std::cout << "Hello, Concurrent World!\n" << std::endl;
    std::cout << "Hello, Concurrent World!\n";
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

    
}