#ifndef CS4280_P0_TREE_H
#define CS4280_P0_TREE_H

#include "node.h"
#include "stringOp.h"
using namespace std;

class Tree {
private:
    Node* root;
    void insert(Node *&, Node *&);
    void displayInOrder(Node *) const;
public:
    Tree()
    { root = NULL; } 

    char getLast(Node *&); 

    void insertNode(string);

    void buildTree(fstream&);
    void printInorder(string);
    void printPreorder(string);
    void printPostorder(string);

};

#endif
