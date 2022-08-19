#include "socket_helpers.h"

int main(int argc, char *argv[]){
    cout << MY_OS << endl;
    if(!check_and_start_if_windows()){ return 0; }

    return 0;
}