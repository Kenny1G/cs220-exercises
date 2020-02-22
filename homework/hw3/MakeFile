# name: Kenneth Oseleononmen
# ID:   KOSELEO1

CC = gcc
CONSERVATIVE_FLAGS = -std=c99 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
FLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)


hw3: hw3.o dnasearch.o
	$(CC) hw3.o dnasearch.o -o hw3

hw3.o: hw3.c dnasearch.h 
	$(CC) $(FLAGS) -c hw3.c -o hw3.o

test_dnasearch: test_dnasearch.o dnasearch.o 
	$(CC) test_dnasearch.o dnasearch.o -o test_dnasearch 

dnasearch.o: dnasearch.c dnasearch.h 
	$(CC) $(FLAGS) -c dnasearch.c

test_dnasearch.o: test_dnasearch.c dnasearch.h
	$(CC) $(FLAGS) -c test_dnasearch.c

clean:
	rm -f *.o test_dnasearch hw3



