# Define the machine object files for your program
OBJECTS = main.o BinarySearchTree.o
# Define your include file
INCLUDES = BinarySearchTree.h

# make for the executable
p3: main.o BinarySearchTree.o
	gcc -g -o p3 main.o BinarySearchTree.o

# Simple suffix rules for the .o
main.o: main.c BinarySearchTree.h
	gcc -g -c main.c

BinarySearchTree.o: BinarySearchTree.c BinarySearchTree.h
	gcc -g -c BinarySearchTree.c

# Clean the .o files
clean:
	rm -f *.o p3


