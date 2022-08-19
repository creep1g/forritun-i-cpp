#include <iostream>
#include "data_processing.h"
#include <thread>
#include <pthread.h>

pthread_mutex_t lock;

void process_stuff(DataStore &ds, DataProcessing dproc, int my_number){
    std::cout << "Processor #" << my_number << " starting" << std::endl;
    while(!ds.is_empty()){
        DataPart dp = ds.get_next();
        std::cout << "Processor #" << my_number << " processing data: " << dp << std::endl;
        pthread_mutex_lock(&lock);
        int result = dproc.process(dp);
        pthread_mutex_unlock(&lock);
        std::cout << "Processor #" << my_number << " RESULT: " << result << std::endl;

    }
    std::cout << "Processor #" << my_number << " STOPPING" << std::endl;
}

int main(){
    DataStore ds;
    DataProcessing dproc;
    std::thread dataThreads[5];
    for(int i = 0; i < 5; i++){
      dataThreads[i] = std::thread(process_stuff, std::ref(ds), dproc, i+1);
    }
    for(int i = 0; i <5; i++){
      dataThreads[i].join();
    }

    return 0;
}
