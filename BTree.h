#ifndef BTREE_H
#define BTREE_H

///////////////////
// Node Struct
///////////////////
struct Node {
    Node* nodes;  // array of child nodes
    int* keys;  // array of keys for the current node
};

///////////////////
// BTree Class
///////////////////
class BTree {
private:

public:
};

#endif