#include <iostream>

#include "socket_helpers.h"

using namespace std;

int main(){
    cout << MY_OS << endl;
    if(!check_and_start_if_windows()){ return 0; }

    //TODO: Write client and connect to ip: 127.0.0.1 (localhost) and port: 4061 (or other)

    return 0;
}