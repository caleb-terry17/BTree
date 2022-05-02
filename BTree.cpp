#include "BTree.h"

///////////////////
// BTree public member function definitions
///////////////////
// default constructor
// creates an empty node at the root of the tree
BTree::BTree(int t) : t(t) {
    depth = 0;  // currently no nodes in the tree
    root = new Node();
    root->leaf = true;  // only node in the tree currently
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

// getRoot: returns a reference to the root node
const Node* BTree::getRoot() const { return root; }

// insert: inserts a key into the tree in the correct spot
void BTree::insert(int key) {
    // navigating to leaf where node goes
    Node* node = root;
    while (!node->leaf) {
        for (int i = 0; i < node->keys.size(); ++i) {
            if (key < node->keys.at(i)) {
                // need to search through ith child
                node = node->children.at(i);
                break;
            }
        }
        // need to search through last child because key > all keys in node
        node = node->children.at(node->children.size());
    }

    // found leaf => attempt insert
    if (node->keys.size() < (2 * t - 1)) {
        // space to insert => insert
        for (std::vector<int>::iterator itr = node->keys.begin(); itr != node->keys.end(); ++itr) {
            if (key < *itr) {
                // insert here
                node->keys.insert(itr, key);
                // value is inserted => done with function
                return;
            }
        }
        // made it through all keys => insert at end before end iterator
        node->keys.insert(node->keys.end(), key);
        return;
    }

    // cannot, inform and return
    std::cout << "cannot insert, leaf full" << std::endl;
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

///////////////////
// BTree helper functions
///////////////////
// ostream operator
// NOTE: need to update this later!!!
std::ostream& operator<<(std::ostream& out, const BTree& tree) {
    out << "(";
    for (int i = 0; i < tree.getRoot()->keys.size(); ++i) {
        out << tree.getRoot()->keys.at(i) << ", ";
    }
    out << "\b\b)";
    return out;
}