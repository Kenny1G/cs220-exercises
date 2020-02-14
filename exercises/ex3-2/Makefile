# Sample Makefile

CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -g

# Links together files needed to create executable
main: main_file.o functions.o
	$(CC) -o main main_file.o functions.o

# Compiles mainFile.c to create mainFile.o
# Note that we list functions.h here as a file that
# main_file.c depends on, since main_file.c #includes it
main_file.o: run_concat.c string_functions.h
	$(CC) $(CFLAGS) -c run_concat.c -o main_file.o

# Compiles functions.c to create functions.o
# Note that we list functions.h here as a file that
# functions.c depends on, since functions.c #includes it
functions.o: string_functions.c string_functions.h
	$(CC) $(CFLAGS) -c string_functions.c -o functions.o

# Removes all object files and the executable named main,
# so we can start fresh
clean:
	rm -f *.o main
