CXX=clang++

CFlags = -g -Wall

algorithm: main.o

main.o: main.cpp
	clang++ -c main.cpp

clean: rm algorithm main.o
