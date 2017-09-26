#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

class Fraction {
public:
    Fraction();
    Fraction(int top);
    Fraction(int top, int bottom);
    int getTop();
    int getBottom();
    void fixFraction();
    int gcd(int n, int m);
private:
    int topNum;
    int bottomNum;

};

class FractionException {
public:
    FractionException(const string&);
    string what();

private:
    string message;
};