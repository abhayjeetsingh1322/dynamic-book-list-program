# Comments in a Makefile start with a sharp sign

# Default target all, builds the lab3 executable and prepares submission zip
all: lab3 lab3.zip

# Target to create a .zip file for submission, depends on lab3
lab3.zip: lab3 Makefile LAB3README lab3.c lab3.h
	zip lab3.zip Makefile LAB3README lab3.c lab3.h

# Target for the lab3 executable, depends on lab3.o
lab3: lab3.o
	gcc lab3.o -o lab3

# Compiles lab3.c to lab3.o, depends on lab3.c and lab3.h
lab3.o: lab3.c lab3.h
	gcc -std=c99 -pedantic -g -c lab3.c -o lab3.o

# Custom target for running the program normally
run: lab3
	./lab3

# Cleans up generated files
clean:
	rm -rf *.o lab3 lab3.zip

