#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct Node {
    string value;
    char last;
    Node *left;
    Node *right;
    Node *middle;
};
