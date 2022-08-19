#include <iostream>
#include <thread>

void raise_number(int number){
    number += 1;
}

int main(){
    int the_number = 0;
    std::thread mythread(raise_number, the_number);
    mythread.join();
    std::cout << the_number << std::endl;
    return 0;
}
