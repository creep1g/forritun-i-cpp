#include <iostream>

#include "socket_helpers.h"

using namespace std;

int main(){
    cout << MY_OS << endl;
    if(!check_and_start_if_windows()){ return 0; }

    //TODO: Write server and connect to port: 4061

    return 0;
}