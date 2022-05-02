#ifndef BTREE_H
#define BTREE_H

#include <vector>
#include <iostream>

///////////////////
// Node Struct
///////////////////
struct Node {
    // NOTE: there will always be one more child node than there are keys
    std::vector<Node*> children;  // array of child nodes (nullptr if leaf)
    std::vector<int> keys;  // array of keys for the current node
    bool leaf;  // true if the node is a leaf

    // default constructor
    Node() : children(std::vector<Node*>()), keys(std::vector<int>()), leaf(false) {}
};

///////////////////
// BTree Class
///////////////////
class BTree {
private:
    Node* root;  // root node of the tree
    int depth;  // depth of the tree
    int t;  // load value of tree

    // private member functions
    // clear: recursive function that goes to its child and then deletes its nodes
    void clear(Node* node);

public:
    // default constructor
    BTree(int t = 2);
    // copy constructor
    BTree(BTree& tree);
    // move constructor
    BTree(BTree&& tree);
    // copy assignment operator
    BTree& operator=(BTree& tree);
    // move assignment operator
    BTree& operator=(BTree&& tree);
    // destructor
    ~BTree();

    // public member functions
    // getRoot: returns a reference to the root node
    const Node* getRoot() const;
    // insert: inserts a key into the tree in the correct spot
    void insert(int key);
};

// helper functions
// ostream operator
std::ostream& operator<<(std::ostream& out, const BTree& tree);

#endif