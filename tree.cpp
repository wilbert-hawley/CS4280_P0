#include "tree.h"
#include <sstream>
using namespace std;

// insertNode creates a new node and passes it to insert along with the root
void Tree::insertNode(string str) {
    Node *newNode = NULL;

    newNode = new Node;
    newNode->value = str;
    newNode->left = newNode->right = newNode->middle = NULL;

    insert(root, newNode);
}

// insert travels down the tree and inserts the new node where appropriate
void Tree::insert(Node *& nodePtr, Node *&newNode) {
    if (nodePtr == NULL)
        nodePtr = newNode;
    else if (getLast(newNode) == getLast(nodePtr))
        insert(nodePtr->middle, newNode);
    else if (getLast(newNode) < getLast(nodePtr))
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

// displayInOrder travels down the tree InOrder and prints to file.
void Tree::displayInOrder(Node *nodePtr, int level, fstream& file)
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left, level + 1, file);
        file << strTreeFormat(nodePtr->value, getLast(nodePtr), level);;
        displayInOrder(nodePtr->middle, level + 1, file);
        displayInOrder(nodePtr->right, level + 1, file);
    }
}

// displayPreOrder travels down the tree InOrder and prints to file.
void Tree::displayPreOrder(Node *nodePtr, int level, fstream& file)
{
    if (nodePtr)
    {
        file << strTreeFormat(nodePtr->value, getLast(nodePtr), level);
        displayPreOrder(nodePtr->left, level + 1, file);
        displayInOrder(nodePtr->middle, level + 1, file);
        displayPreOrder(nodePtr->right, level + 1, file);
    }
}

// displayPostOrder travels down the tree InOrder and prints to file.
void Tree::displayPostOrder(Node *nodePtr, int level, fstream& file)
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left, level + 1, file);
        displayInOrder(nodePtr->middle, level + 1, file);
        displayPostOrder(nodePtr->right, level + 1, file);
        file << strTreeFormat(nodePtr->value, getLast(nodePtr), level);
    }
}

// getLast returns the last character of the value held in a node.
char Tree::getLast(Node *&nodePtr) {
    return nodePtr->value[nodePtr->value.length() - 1];
}

// buildTree
void Tree::buildTree(fstream& file) {

    string holder = strBuild(file);

    stringstream stream(holder);

    string input;

    while(getline(stream, input, ' ')) {
        if(inputCheck(input))
            insertNode(input);
    }
}


void Tree::printInOrder(string output) {
    string final("./" + output + ".inorder");

    fstream file;
    file.open(final.c_str(), ios_base::out);
    if(!file)
        errorMessage("P0: tree.cpp: ", final, " failed to open. Abort.");

    displayInOrder(root, 0, file);
    file.close();
}


void Tree::printPreOrder(string output) {
    string final("./" + output + ".preorder");

    fstream file;
    file.open(final.c_str(), ios_base::out);
    if(!file)
        errorMessage("P0: tree.cpp: ", final, " failed to open. Abort.");

    displayPreOrder(root, 0, file);
    file.close();
}


void Tree::printPostOrder(string output) {
    string final("./" + output + ".postorder");

    fstream file;
    file.open(final.c_str(), ios_base::out);
    if(!file)
        errorMessage("P0: tree.cpp: ", final, " failed to open. Abort.");

    displayPostOrder(root, 0, file);
    file.close();
}
