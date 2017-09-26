#include "fraction_12ns73.h"

using namespace std;

// should return 0/1
Fraction::Fraction() {
    topNum = 0;
    bottomNum = 1;
}


Fraction::Fraction(int t) {
    topNum = t;
    bottomNum = 1;
}

Fraction::Fraction(int top, int bottom) {
    topNum = top;
    bottomNum = bottom;
    if(bottom == 0) {
        throw (FractionException("Can't have 0 on bottom, not a fraction"));
    }
    fixFraction();

}


int Fraction::getTop() {
    return topNum;
}

int Fraction::getBottom() {
    return bottomNum;
}

void Fraction::fixFraction() {
    int s = 1;
    if(topNum < 0) {
        s = -s;
        topNum = -topNum;
    }
    if (bottomNum < 0) {
        s = -s;
        topNum = -topNum;
    }

    for (int i = bottomNum * topNum; i >1; i--) {
        if(bottomNum % i == 0 && topNum % i == 0) {
            bottomNum /= i * s;
             topNum /= i;
        }

    }

}

ostream& operator << (ostream& output,  Fraction& frac) {
    return output << frac.getTop() << "/" << frac.getBottom() << endl;
}

FractionException::FractionException(const string &m) : message(m) {};

string FractionException::what() {
    return message;
}

int main () {
Fraction test(4/2);
    cout << test;
}
