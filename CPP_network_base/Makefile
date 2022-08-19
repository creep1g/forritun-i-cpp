
all: network_main

network_main: socket_helpers.h socket_helpers.cpp network_main.cpp
	g++ -std=c++11 -o network network_main.cpp socket_helpers.cpp -pthread
