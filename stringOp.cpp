#include "stringOp.h"
using namespace std;

void strClean(string& str) {
    for(int i = 0; i < str.length(); i++) {
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

    while(getline(file, input)) {
        strClean(input);
        holder += input;
    }

    return holder;
}

string strTreeFormat(string value, char c, int level) {
    string build = "";
    build.append(level * 2, ' ');
    build.append(1, c);
    build.append(": ");
    build.append(value);
    build.append("\n");
    return build;

}
