#include "stringOp.h"
using namespace std;

void strClean(string& str) {
    for(int i = 0; i < str.length(); i++) {
        if(isspace(str[i]))
            str[i] = ' ';
    }

    while(isspace(str[str.length() - 1]))
        str.erase((str.length() - 1), 1);

}
