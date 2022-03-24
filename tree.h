#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "stringOp.h"
#include <sstream>
using namespace std;

// Most of this class is adapted from CS 1250/2250 textbook.
class Tree {
private:
    Node* root;
    void insertNode(string);
    void insert(Node *&, Node *&);
    void displayInOrder(Node*, int, fstream&);
    void displayPreOrder(Node*, int, fstream&);
    void displayPostOrder(Node*, int, fstream&);
    char getLast(Node *&);

public:
    Tree() { root = NULL; }
    void buildTree(fstream&);
    void printInOrder(string);
    void printPreOrder(string);
    void printPostOrder(string);
};

#endif
