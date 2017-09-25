#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

class Fraction {
public:
    Fraction();
    Fraction(int t);
    Fraction(int t, int b);
    int getTop();
    int getBottom();
    void fixFraction();
    void gcd(int m, int m);
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