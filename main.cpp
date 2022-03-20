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

    return 0;
}
