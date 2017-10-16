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
    int getTop() const ;
    int getBottom() const;
    void fixFraction();
    Fraction& operator-();
    Fraction& operator++();// pre
    Fraction& operator++(int makeEZtoSeeThatItisPost); // post


private:
    int topNum;
    int bottomNum;
};
//IO
ostream& operator<<(ostream& output,  const Fraction& frac);
istream& operator>>(istream &input,  Fraction& frac);

// arithmetic op
Fraction operator+( const Fraction& left,  const Fraction& right);
Fraction operator-(const Fraction& left,  const Fraction& right);
Fraction operator*( const Fraction& left, const  Fraction& right);
Fraction operator/( const Fraction& left, const  Fraction& right);
Fraction operator+=(Fraction& left, Fraction& right);
//comparing ops
bool operator>(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);







class FractionException {
public:
    FractionException(const string&);
    string what();

private:
    string message;
};