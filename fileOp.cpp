#include "fileOp.h"
using namespace std;

void buildFile(fstream &fi, string str) {
    fi.open(str.c_str(), fstream::out);
    if(!fi) {
        errorMessage("P0: fileOp.cpp: ", str, " failed to open");
    }
    cout << "Reading in from std and creating temporary file. If typing, use ctrl-D to simulate"
         <<  " end of file.\n";
    string temp;

    while(getline(cin, temp)) {
        fi << temp.append("\n");
    }

    fi.close();
}

void emptyFileTest(fstream& file, string filename) {

    string input;
    int i = 0;

    while(getline(file, input)) {
        i++;
    }

    if(i == 0){
        errorMessage("P0: fileOp.cpp: ", filename, " was empty. Abort.");
    }
    file.close();
    file.open(filename.c_str(), fstream::in);
}
