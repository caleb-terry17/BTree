#ifndef BTREE_H
#define BTREE_H

///////////////////
// Node Struct
///////////////////
struct Node {
    Node* nodes;  // array of child nodes (nullptr if leaf)
    int* keys;  // array of keys for the current node
    bool leaf;  // true if the node is a leaf

    // default constructor
    Node() : nodes(nullptr), keys(nullptr), leaf(false) {}
};

///////////////////
// BTree Class
///////////////////
class BTree {
private:
    Node* root;  // root node of the tree
    int depth;  // depth of the tree

public:
    // default constructor
    BTree();
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
};

#endif