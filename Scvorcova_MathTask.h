#ifndef _SCVORCOVA_MATHTASK_H
#define _SCVORCOVA_MATHTASK_H

#include <cstring>
#include <cmath>
using namespace std;


double convertToMegabytes(double B) {
    return B / 1024;
}

double convertToGigabytes(double B) {
    return B / 1024 / 1024;
}

bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
    }
    catch (...) //если возникла ошибка в блоке try
    { return false; }
    return true;
}
#endif