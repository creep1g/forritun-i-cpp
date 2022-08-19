#include <iostream>
#include <pthread.h>
#include <thread>
#include "data_processing.h"

pthread_mutexattr_t attr;
pthread_mutex_t lock;

void process_data(int my_number, DataStorage &ds){
    std::cout << "processor #" << my_number << " starting" << std::endl;
    while(!ds.is_empty()){
        DataPiece dp = ds.get_next();
        std::cout << "processor #" << my_number << " processing data: " << dp << std::endl;
        int result = DataProcessor::process_data(dp);
        std::cout << "processor #" << my_number << " RESULT: " << result << std::endl;
    }
    std::cout << "processor # " << my_number << " STOPPING" << std::endl;
}

int main(){

    DataStorage ds;
    
    std::thread dataThreads[7];
    
    for(int i = 0; i < 7; i++){
      dataThreads[i] = std::thread(process_data, i+1, std::ref(ds));
    }
    for(int i = 0; i < 7; i++){
      dataThreads[i].join();
    }

    return 0;
}
