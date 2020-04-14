#Kenneth Oseleononmen
#koseleo1
CC = g++
FLAGS = -Wall -Wextra -pedantic -g -O0 -std=c++11

cTreeTest: CTree.o cTreeTest.o
	$(CC) $(FLAGS) CTree.o cTreeTest.o -o cTreeTest

tTreeTest: tTreeTest.o
	$(CC) $(FLAGS) tTreeTest.o -o tTreeTest

tTreeTest.o: TTreeTest.cpp Tree.h Tree.inc
	$(CC) $(FLAGS) -c TTreeTest.cpp

cTreeTest.o: CTreeTest.cpp  CTree.h
	$(CC) $(FLAGS) -c CTreeTest.cpp -o cTreeTest.o

CTree.o: CTree.cpp CTree.h 
	$(CC) $(FLAGS) -c CTree.cpp -o CTree.o


clean:
	rm -f *.o cTreeTest tTreeTest


