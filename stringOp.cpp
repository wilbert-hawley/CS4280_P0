#include "stringOp.h"
using namespace std;

// strClean takes in a a string by reference and cleans it up
void strClean(string& str) {

    // change any space character to " "
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if(isspace(str[i]))
            str[i] = ' ';
    }

    // Delete extra spaces off the front
    while(isspace(str[0]))
        str.erase(0, 1);

    // Delete extra spaces off the back
    while(isspace(str[str.length() - 1]))
        str.erase((str.length() - 1), 1);

    // add one space for concatenation
    str.append(" ");
}


// strBuild goes through a file and concatenates the contents into
// one string to return to buildTree
string strBuild(fstream &file) {
    string holder = "";
    string input;

    while(getline(file, input)) {
        // clean up the string before adding it
        strClean(input);
        holder += input;
    }

    return holder;
}

// strTreeFormat creates the string needed to write in the proper format
// for the file and returns it.
string strTreeFormat(string value, char c, int level) {
    string build = "";
    build.append(level * 2, ' ');
    build.append(1, c);
    build.append(": " + value + "\n");
    return build;
}

// inputCheck makes sure the current string isn't an empty space
// or a blank string.
bool inputCheck(string str) {
    if(isspace(str[0]) || str == "")
        return false;
    return true;
}

// errorMessage simply takes in the location, filename, and message
// for user and then exits program due to the error.
void errorMessage(string location, string filename, string message) {
    cout << location << filename << message << endl;
    exit(1);
}