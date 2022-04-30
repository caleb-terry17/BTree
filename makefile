all:
	g++ main.cpp BTree.cpp 

run:
	valgrind --leak-check=full ./a.out