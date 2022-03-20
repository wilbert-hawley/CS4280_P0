#include "stringOp.h"
#include <stdlib.h>
using namespace std;

void strClean(string& str) {
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if(isspace(str[i]))
            str[i] = ' ';
    }

    while(isspace(str[0]))
        str.erase(0, 1);

    while(isspace(str[str.length() - 1]))
        str.erase((str.length() - 1), 1);

    str.append(" ");
}

string strBuild(fstream &file) {
    string holder = "";
    string input;
    int i = 0;

    while(getline(file, input)) {
        i++;
        strClean(input);
        holder += input;
    }

    if(i == 0){
       cout << "file was empty. aborting\n";
       exit(1);
    }

    return holder;
}

string strTreeFormat(string value, char c, int level) {
    string build = "";
    build.append(level * 2, ' ');
    build.append(1, c);
    build.append(": " + value + "\n");
    return build;

}

bool inputCheck(string str) {
    if(isspace(str[0]) || str == "")
        return false;
    return true;
}

void errorMessage(string location, string filename, string message) {
    cout << location << filename << message << endl;
    exit(1);
}