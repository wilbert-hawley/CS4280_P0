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
        buildFile(file, filename + ".sp2022");
    }
    else if(argc == 2) {
        filename = argv[1];
    }
    else {
        cout << "P0: main.cpp: Too many arguments. Abort.\n";
        return 1;
    }

    file.open((filename + ".sp2022").c_str(), fstream::in);

    if(!file)
        errorMessage("P0: main.cpp: ", filename + ".sp2022 ", "failed to open");

    emptyFileTest(file, filename + ".sp2022");

    Tree tree;

    tree.buildTree(file);
    tree.printInorder(filename);
    tree.printPreorder(filename);
    tree.printPostorder(filename);

    file.close();

    return 0;
}
