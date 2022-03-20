#include "tree.h"
#include <sstream>
using namespace std;

void Tree::displayInOrder(Node *nodePtr, int level, fstream& file)
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left, level + 1, file);

        string complete = strTreeFormat(nodePtr->value, getLast(nodePtr), level);
        file << complete;

        displayInOrder(nodePtr->middle, level + 1, file);
        displayInOrder(nodePtr->right, level + 1, file);
    }
}

void Tree::displayPreOrder(Node *nodePtr, int level, fstream& file)
{
    if (nodePtr)
    {
        string complete = strTreeFormat(nodePtr->value, getLast(nodePtr), level);
        file << complete;
        displayPreOrder(nodePtr->left, level + 1, file);
        displayInOrder(nodePtr->middle, level + 1, file);
        displayPreOrder(nodePtr->right, level + 1, file);
    }
}

void Tree::displayPostOrder(Node *nodePtr, int level, fstream& file)
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left, level + 1, file);
        displayInOrder(nodePtr->middle, level + 1, file);
        displayPostOrder(nodePtr->right, level + 1, file);
        string complete = strTreeFormat(nodePtr->value, getLast(nodePtr), level);
        file << complete;
    }
}

char Tree::getLast(Node *&nodePtr) {
    return nodePtr->value[nodePtr->value.length() - 1];
}

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

void Tree::insertNode(string str) {
    Node *newNode = NULL;	
    
    newNode = new Node;
    newNode->value = str;
    newNode->left = newNode->right = newNode->middle = NULL;

    insert(root, newNode);
}

void Tree::buildTree(fstream& file) {

    string holder = strBuild(file);

    stringstream stream(holder);

    string input;

    while(getline(stream, input, ' ')) {
        insertNode(input);
    }
    
    cout << "buildTree is done running\n";
}


void Tree::printInorder(string output) {
    string final("./");
    final.append(output);
    final.append(".inorder");
    fstream file;
    file.open(final.c_str(), ios_base::out);
    if(!file) {
        cout << "no";
        return;
    }
    displayInOrder(root, 0, file);
    file.close();
}


void Tree::printPreorder(string output) {
    string final("./");
    final.append(output);
    final.append(".preorder");
    fstream file;
    file.open(final.c_str(), ios_base::out);
    if(!file) {
        cout << "no";
        return;
    }
    displayPreOrder(root, 0, file);
    file.close();
}


void Tree::printPostorder(string output) {
    string final("./");
    final.append(output);
    final.append(".postorder");
    fstream file;
    file.open(final.c_str(), ios_base::out);
    if(!file) {
        cout << "no";
        return;
    }
    displayPostOrder(root, 0, file);
    file.close();
}
