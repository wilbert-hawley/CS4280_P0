#ifndef NODE_H
#define NODE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

// Node struct to hold the string values as well as the three pointers
struct Node {
    string value;
    Node *left;
    Node *right;
    Node *middle;
};

#endif