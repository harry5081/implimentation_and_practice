#include <iostream>
#include <thread>
#include <functional>

#include <vector>
#include <mutex>

#define NUM_THREADS 10

// g++ ../src/hello.cpp -lpthread -o hello

void Hello(){
    // std::cout << "Hello, Concurrent World!\n" << std::endl;
    std::cout << "Hello, Concurrent World!\n";
}

void Clear(int &data){
    data = 0;
}

std::thread CreateHello(){
    std::thread t_return{[](){std::cout<<"Hello, return thread!"<<std::endl;}};
    return t_return;
}

// 2-7
int Sum(int N){
    int result = 0;
    for(int i = 1; i <= N; i++){
        result += 1; // possible to be computed in parallel
                     // since sequence change won't affect the result
    }
    return result;
}
// 2-7
void Add(int& result, int i){
    // result += 1;
    int s = result + i;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    result = s;
}
// 2-7
int SumThread(int N){
    int result = 0;
    for(int i = 1; i <= N; i++){
        std::thread t(Add, std::ref(result), i); // there will only be two thread, namely main() and the thread
        t.join();
    }
    return result;
}
// 2-7
// problem: if N is a large num, them there will be too many threads
int SumParallelWrong(int N){
    std::vector<std::thread> threads;
    int result = 0;
    for(int i = 1; i <= N; i++){
        // threads.push_back(std::thread(Add, std::ref(result), i));
        threads.emplace_back(Add, std::ref(result),i);
    }
    for(auto& t : threads){
        t.join();
    }
    return result;
}

// 2-8
void RangeSum(int& result, int begin, int end){
    result = 0;
    for(int i = begin; i < end; i++){
        result += 1;
    }
}
// 2-8
int SumParallelDivide(int n){
    std::vector<int> rangeSumResult(3);
    std::vector<std::thread> threads;
    //for(){ //1:36 // refer to 2-8 slide

    //}

    return 0;

}

// 3-3
void AddWithLock(int& result, int i, std::mutex& m){
    
    // 3-4
    std::lock_guard<std::mutex> l(m);
    // m.lock();
    int s = result + i;
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    result = s;
    std::cout << result << " ";
    // m.unlock();
}

int main(){
    std::cout << "This is main Thread!" << std::endl;
    std::cout << "The hardware supports " << std::thread::hardware_concurrency() << " threads" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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

    // 2-5
    // send callable with argument, and call by reference
    int data = 10;
    std::thread t_reference(Clear, std::ref(data));
    t_reference.join();
    std::cout << "data:" << data << std::endl;

    // 2-6
    std::thread t1{[](){std::cout<< "use move to copy thread" <<std::endl;}};
    std::thread t2 = std::move(t1);
    t2.join();

    std::thread t_return = CreateHello();
    t_return.join();

    // 2-7
    std::cout<< "Sum Wrong:"<< SumParallelWrong(10)<< std::endl;

    // 2-8
    std::thread lambda_t([](){
        std::cout << "This is lambda thread" << std::endl;
    });
    lambda_t.join();

    // 2-10 lambda expression for multi-thread

    // 3-3 mutex
    std::cout << "MUTEX" << std::endl; 
    std::mutex m;
    std::vector<std::thread> threads3;
    int result3 = 0;
    for(int i = 0; i<10; i++){
        threads3.emplace_back(AddWithLock, std::ref(result3), i, std::ref(m));
    }
    for(auto& t : threads3){
        t.join();
    }

    // 3-7
    std::recursive_mutex recur_m;

    

}