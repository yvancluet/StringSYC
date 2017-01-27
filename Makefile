all: main

main: main.o string.o
	g++ -g main.o string.o -Wall -Wextra -o main -std=c++11
	
main.o: main.cpp string.h
	g++ -g -c main.cpp -Wall -Wextra -o main.o -std=c++11
	
string.o : string.cpp string.h
	g++ -g -c string.cpp -Wall -Wextra -o string.o -std=c++11
