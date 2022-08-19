#include <iostream>
#include <thread>
#include <mutex>

std::mutex print_mutex;

void thread_runner(int sleeptime){
    std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime));
    print_mutex.lock();
    std::cout << "I am a thread" << std::endl;
    print_mutex.unlock();
}

int main(){
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    rand();

    for(int i = 0; i < 4; i++){
        std::thread mythread(thread_runner, rand() % 1000);
        mythread.join();
    }
    std::cout << "All threads are done" << std::endl;
    return 0;
}
