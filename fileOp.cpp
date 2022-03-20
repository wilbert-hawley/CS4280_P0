#include "fileOp.h"
using namespace std;

void buildFile(fstream &fi, string str) {
    fi.open(str.c_str(), fstream::out);
    if(!fi) {
        cout << "temp file won't work\n";
        return;
    }
    cout << "Reading in from std and creating temporary file:\n";
    string temp;
    while(getline(cin, temp)) {
        fi << temp.append("\n");
    }
    fi.close();
}
