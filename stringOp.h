#ifndef STRINGOP_H
#define STRINGOP_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void strClean(string&);
string strBuild(fstream&);
string strTreeFormat(string, char, int);
bool inputCheck(string);
void errorMessage(string, string, string);

#endif