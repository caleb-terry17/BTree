#include "BTree.h"

///////////////////
// BTree public member function definitions
///////////////////
// default constructor
// creates an empty node at the root of the tree
BTree::BTree(int t) : t(t) {
    depth = 0;  // currently no nodes in the tree
    root = new Node();
}

// copy constructor
BTree::BTree(BTree& tree) {}

// move constructor
BTree::BTree(BTree&& tree) {}

// copy assignment operator
BTree& BTree::operator=(BTree& tree) {}
// move assignment operator
BTree& BTree::operator=(BTree&& tree) {}

// destructor
BTree::~BTree() {
    clear(root);
}

// insert: inserts a key into the tree in the correct spot
void insert(int key) {
    
}

///////////////////
// BTree private member function definitions
///////////////////
// clear: recursive function that goes to its child and then deletes its nodes
void BTree::clear(Node* node) {
    // if not a leaf, need to visit children
    if (!(node->leaf)) {
        for (int i = 0; i < node->children.size(); ++i) {
            clear(node->children.at(i));
        }
    }
    // delete this guy
    delete node;
}