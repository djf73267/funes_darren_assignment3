LFLAG= -Wall
CFLAGS= -Wall -std=c++14 -g -O0 -pedantic-errors


main: main.cpp BinaryTree.o DataType.o
	g++ $(LFLAG) -o main main.cpp BinaryTree.o DataType.o -g
run: main.cpp BinaryTree.o DataType.o
	g++ -std=c++14 -g -o run main.cpp BinaryTree.o DataType.o -g

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ $(CFLAGS) -c BinaryTree.cpp

DataType.o: DataType.cpp DataType.h
	g++ $(CFLAGS) -c DataType.cpp

clean:
	rm *.o main