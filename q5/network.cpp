
#include <iostream>
#include <string.h>
#include <thread>

#ifdef _WIN32
    #define MY_OS "Windows"
    #include <WinSock2.h>
    typedef SOCKET SOCKET_TYPE;
    typedef int ADDRESS_SIZE;
    #define ON_WINDOWS
#else
    #define MY_OS "NOT Windows"
    typedef int SOCKET_TYPE;
    typedef unsigned int ADDRESS_SIZE;
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <errno.h>
#endif

#define TCP_PORT 4037 //IPEN TCP PORTS ON SKEL: 4000-4100
#define UDP_PORT 4101 //IPEN UDP PORTS ON SKEL: 4100-4200

using namespace std;

bool check_and_start_if_windows(){
    #ifdef ON_WINDOWS
        WSADATA wsa_data;
        if(WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0){
            cout << "failed at WSAStartup()" << endl;
            return false;
        }
    #endif
    return true;
}

void make_socket_address(sockaddr *address, int port, std::string ip_address = ""){
    sockaddr_in *socket_address = (sockaddr_in*)address;
    socket_address->sin_family = AF_INET;
    socket_address->sin_port = htons(port);
    if(ip_address == ""){
        socket_address->sin_addr.s_addr = INADDR_ANY;
    }
    else{
        socket_address->sin_addr.s_addr = inet_addr(ip_address.c_str());
    }
}



int main(){
    check_and_start_if_windows();
    SOCKET_TYPE my_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr socket_address;
    make_socket_address(&socket_address, TCP_PORT);
    ADDRESS_SIZE addr_size = sizeof(socket_address);

       SOCKET_TYPE new_socket = accept(my_socket, (sockaddr *)&socket_address, &addr_size);


    listen(my_socket, 1);

    if(new_socket == -1 || new_socket == ~0){
        cout << "invalid socket" << endl;
        return false;
    }
}
