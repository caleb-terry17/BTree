#include "BTree.h"

int main() {
    // testing default constructor + destructor + clear
    BTree tree1;

    // testing insert
    tree1.insert(5);
    tree1.insert(8);
    tree1.insert(3);

    // testing << operator + insert
    std::cout << tree1 << std::endl;
}