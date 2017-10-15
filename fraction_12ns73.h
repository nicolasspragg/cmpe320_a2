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


private:
    int topNum;
    int bottomNum;

};

ostream& operator << (ostream& output,  Fraction& frac);
Fraction operator+( const Fraction& left,  const Fraction& right);
Fraction operator-(const Fraction& left,  const Fraction& right);
Fraction operator-( const Fraction& fraction); // negation
Fraction operator*( const Fraction& left, const  Fraction& right);
Fraction operator/( const Fraction& left, const  Fraction& right);
Fraction operator+=( Fraction& left, Fraction& right);



class FractionException {
public:
    FractionException(const string&);
    string what();

private:
    string message;
};