#include "tree.h"
using namespace std;

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

void Tree::buildTree(fstream& file, string filename) {
    
    // if flag == true then read from standard input
    // if flag == false then read from file
    // both go in temporary file

    /*fstream temp;
    temp.open("temp.txt", fstream::out);
    //strClean("hey");
    string input;
    if (flag) {
        printf("Please enter DONE when finished or it will read to the end of file:\n");
        while(getline(cin, input)) {
            if(input == "DONE")
               break; 
            temp << input;
        }
    }
    else {
        cout << "Program will read in from file provided.\n";
        while(getline(file, input)) {
            if(input == "DONE")
               break;
            temp << input;
        }      
    }*/

    

    string holder = "";
    string input;

    while(getline(file, input)) {
        cout << "hey";
        holder += input;
    }

    cout << "Holder = " << holder;
    
    cout << "buildTree is done running\n";
}
void Tree::printInorder(string) {
	cout << "printInorder is working\n";
}
void Tree::printPreorder(string) {
	cout << "printPreorder is working\n";
}
void Tree::printPostorder(string) {
	cout << "printPostorder is working\n";
}
