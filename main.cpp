#include <iostream>
#include <string>
#include "tree.h"
#include "fileOp.h"
using namespace std;

int main(int argc, char** argv) {


    fstream file;
    string filename;

    if(argc == 1) {
        filename = "output";
        buildFile(file, filename);
        file.open(filename.c_str(), fstream::in);
    }
    else if(argc == 2) {
        filename = argv[1];
        file.open((filename + ".sp2022").c_str(), fstream::in);
    }
    else {
        cout << "Too many arguments. Abort.";
        return 1;
    }


    if(!file) {
        cout << "file failed to open\n";
        return 1;
    }

    Tree tree;

    tree.buildTree(file);
    tree.printInorder(filename);
    tree.printPreorder(filename);
    tree.printPostorder(filename);

    file.close();

    return 0;
}
