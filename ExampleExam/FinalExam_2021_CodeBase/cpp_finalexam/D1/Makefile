
all: socket_helpers.h socket_helpers.cpp tcp_client.cpp
	g++ -std=c++11 -o d1 tcp_client.cpp socket_helpers.cpp -pthread

skel:
	scp ./*.cpp ./*.h skel.ru.is:~/cpp_finalexam/D1/
