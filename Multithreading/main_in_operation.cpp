#include <iostream>

#include <thread>
#include <random>
#include <mutex>
#include <chrono>

using namespace std;

#define ARRAY_SIZE 30
#define POOL_SIZE 20

int my_original_array[ARRAY_SIZE];

int my_array[ARRAY_SIZE];
int next_index;

std::mutex edit_mutex;

void edit_next_item(int thread_num){
    edit_mutex.lock();
    cout << "DATA EDITED BY THREAD #" << thread_num << endl;
    int my_index = next_index;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    next_index++;
    edit_mutex.unlock();
    for(int i = 0; i < 20; i++){
        my_array[my_index] += 2;
        my_array[my_index] -= 2;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    my_array[my_index] += 2;
    // my_array[next_index] = edit_int;
}


void edit_items(int thread_num){
    while(next_index < ARRAY_SIZE){
        edit_next_item(thread_num);
    }
}



int main(){
    int seed;
    cout << "Enter a big integer: ";
    cin >> seed;
    srand(seed);
    next_index = 0;
    for(int i = 0; i < ARRAY_SIZE; i++){
        my_array[i] = 1 + (rand() % 50);
    }
    for(int i = 0; i < ARRAY_SIZE; i++){
        my_original_array[i] = my_array[i];
    }
    for(int i = 0; i < ARRAY_SIZE; i++){
        cout << my_array[i] << " ";
    }
    cout << endl << endl;



    std::thread my_threads[POOL_SIZE];

    for(int i = 0; i < POOL_SIZE; i++){
        my_threads[i] = std::thread(edit_items, i + 1);
    }

    for(int i = 0; i < POOL_SIZE; i++){
        my_threads[i].join();
    }

    // std::thread my_thread_1 = thread(edit_items, 1);
    // std::thread my_thread_2 = thread(edit_items, 2);

    // my_thread_1.join();
    // my_thread_2.join();

    for(int i = 0; i < ARRAY_SIZE; i++){
        cout << my_original_array[i] << " ";
    }
    cout << endl << endl;
    for(int i = 0; i < ARRAY_SIZE; i++){
        cout << my_array[i] << " ";
    }
    cout << endl << endl;

    return 0;
}