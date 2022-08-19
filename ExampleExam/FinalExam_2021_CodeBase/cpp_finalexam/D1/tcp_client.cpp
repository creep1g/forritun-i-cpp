#include <iostream>
#include <sys/socket.h>
#include "socket_helpers.h"

using namespace std;

int main(){
    cout << MY_OS << endl;
    if(!check_and_start_if_windows()){ return 0; }

    //TODO: Write client and connect to ip: 130.208.243.61 and port: 4893

    return 0;
}
