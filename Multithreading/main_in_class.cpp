#include <iostream>

#include <thread>
#include <random>
#include <mutex>
#include <chrono>

using namespace std;

#define ARRAY_SIZE 30
#define POOL_SIZE 20


class DataClass{
public:
    DataClass(int data_size, int seed){
        srand(seed);
        next_index = 0;
        for(int i = 0; i < ARRAY_SIZE; i++){
            my_array[i] = 1 + (rand() % 50);
        }
        for(int i = 0; i < ARRAY_SIZE; i++){
            my_original_array[i] = my_array[i];
        }
    }

    bool has_more_data(){
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        if(next_index >= ARRAY_SIZE){
            return false;
        }
        return true;
    }

    int get_next_number(int &index){
        index = next_index;
        next_index++;
        return my_array[next_index - 1];
    }

    void set_number_at(int number, int index){
        my_array[index] = number;
    }

    void print_info(){
            
        for(int i = 0; i < ARRAY_SIZE; i++){
            cout << my_original_array[i] << " ";
        }
        cout << endl << endl;
        for(int i = 0; i < ARRAY_SIZE; i++){
            cout << my_array[i] << " ";
        }
        cout << endl << endl;

    }
private:
    int my_original_array[ARRAY_SIZE];
    int my_array[ARRAY_SIZE];
    int next_index;

};

std::mutex edit_mutex;

bool edit_next_item(int thread_num, DataClass &data){
    edit_mutex.lock();
    if(!data.has_more_data()){
        edit_mutex.unlock();
        return false;
    }
    cout << "DATA EDITED BY THREAD #" << thread_num << endl;
    int my_index;
    int number = data.get_next_number(my_index);
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    edit_mutex.unlock();
    for(int i = 0; i < 20; i++){
        number += 2;
        number -= 2;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    number += 2;
    data.set_number_at(number, my_index);
    // my_array[next_index] = edit_int;
    return true;
}


void edit_items(int thread_num, DataClass &data){
    while(edit_next_item(thread_num, data)){}
}



int main(){
    int seed;
    cout << "Enter a big integer: ";
    cin >> seed;
    DataClass my_data(25, seed);
    cout << endl << endl;



    std::thread my_threads[POOL_SIZE];

    for(int i = 0; i < POOL_SIZE; i++){
        my_threads[i] = std::thread(edit_items, i + 1, std::ref(my_data));
    }

    for(int i = 0; i < POOL_SIZE; i++){
        my_threads[i].join();
    }

    my_data.print_info();

    // std::thread my_thread_1 = thread(edit_items, 1);
    // std::thread my_thread_2 = thread(edit_items, 2);

    // my_thread_1.join();
    // my_thread_2.join();

    return 0;
}