#include "tree.h"
#include "fileOp.h"
using namespace std;

int main(int argc, char** argv) {

    fstream file;
    string filename;

    // Parsing input
    // If no arguments, reading from stdin
    if(argc == 1) {
        filename = "output";
        buildFile(file, filename + ".sp2022");
    }
    // If one argument, attempt to use filename provided
    else if(argc == 2) {
        filename = argv[1];
    }
    // Anymore arguments than 2 means there is an error.
    else {
        cout << "P0: main.cpp: Too many arguments. Abort.\n";
        return 1;
    }

    file.open((filename + ".sp2022").c_str(), fstream::in);

    // Test to make sure file opened successfully. If not, print message and quit
    if(!file)
        errorMessage("P0: main.cpp: ", filename + ".sp2022 ", "failed to open");

    // Testing to see if the file is actually empty before using it.
    emptyFileTest(file, filename + ".sp2022");

    Tree tree;

    // Call build tree, passing in open file.
    tree.buildTree(file);
    cout << "Tree is finished building.\n";

    // Write to file InOrder
    tree.printInOrder(filename);
    cout << "InOrder Traversal written to " << filename << ".inorder\n";

    // Write to file PreOrder
    tree.printPreOrder(filename);
    cout << "PreOrder Traversal written to " << filename << ".preorder\n";

    // Write to file PostOrder
    tree.printPostOrder(filename);
    cout << "PostOrder Traversal written to " << filename << ".postorder\n";

    file.close();

    return 0;
}
