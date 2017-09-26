#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include<fstream>
#include <sstream>
#include<string>
using namespace std;

class Fraction {
public:
    Fraction();
    Fraction(int top);
    Fraction(int top, int bottom);
    int getTop();
    int getBottom();
    void fixFraction();
private:
    int topNum;
    int bottomNum;

};

ostream& operator << (ostream& output,  Fraction& frac);


class FractionException {
public:
    FractionException(const string&);
    string what();

private:
    string message;
};