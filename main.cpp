#include <iostream>
#include <string>
#include "tree.h"
#include "fileOp.h"
using namespace std;

int main(int argc, char** argv) {


    fstream file;
    string filename;

    if(argc == 1) {
        filename = "temp.txt";
        buildFile(file, filename);
    }
    else if(argc == 2) {
        filename = argv[1];
    }
    else {
        cout << "Too many arguments. Abort.";
        return 1;
    }

    file.open(filename.c_str(), fstream::in);

    if(!file) {
        cout << "file failed to open\n";
        return 1;
    }

    Tree tree;

    tree.buildTree(file);
    tree.printInorder("hey");

    cout << "Made it back to main\n";

    file.close();
    /*bool flag = true;
    cout << "List of arguments:\n";
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    if(argc == 0) {
        cout << "error no arguments\n";
    }
    else if(argc == 1) {
        cout << "argc == 1: " << argv[0] << endl;
    }
    else if(argc == 2) {
        cout << "argc == 2: " << argv[0] << "~" << argv[1] << endl;
        flag = false;
    }
    else if(argc == 3) {
        cout << "argc == 3: " << argv[1] << " " << argv[2] << endl;
    }
    else {
        cout << "Too many arguments. Abort.";
        return 1;
    }

    string str;

    cin >> str;

    cout << "str = " << str << endl; 
    fstream input;
    input.open("input.txt", fstream::in);

    if(!input) {
        cout << "file failed to open\n";
    }
    Tree tree;

    tree.buildTree(input, flag);
    tree.printPreorder("hey");
    tree.printInorder("yo");
    tree.printPostorder("hey");

    input.close();*/
        return 0;
}
