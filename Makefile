all:	fifo

fifo:	main.cpp
	g++ -std=c++11 -o fifo main.cpp
