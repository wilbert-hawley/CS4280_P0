#include "tree.h"
#include <sstream>
using namespace std;

void Tree::displayInOrder(Node *nodePtr, int level)
{
    if (nodePtr)
    {

        displayInOrder(nodePtr->left, level + 1);

        string complete = strTreeFormat(nodePtr->value, getLast(nodePtr), level);
        cout << complete;

        //cout << level << " " << getLast(nodePtr) << ": " << nodePtr->value << endl;
        displayInOrder(nodePtr->middle, level + 1);
        displayInOrder(nodePtr->right, level + 1);
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
    displayInOrder(root, 0);
    file.close();
}


void Tree::printPreorder(string) {
	cout << "printPreorder is working\n";
}


void Tree::printPostorder(string) {
	cout << "printPostorder is working\n";
}
