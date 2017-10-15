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


int Fraction::getTop() const{
    return topNum;
}

int Fraction::getBottom() const {
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

Fraction operator+( const Fraction& left,  const Fraction& right) {
    Fraction fractionAfterAdding(left.getTop() * right.getBottom() + left.getBottom() * right.getTop(), left.getBottom() * right.getBottom());
    return fractionAfterAdding;
}

Fraction operator-( const  Fraction& left, const Fraction& right) {
    Fraction fractionAfterAdding(left.getTop() * right.getBottom() - left.getBottom() * right.getTop(), left.getBottom() * right.getBottom());
    return fractionAfterAdding;
}

Fraction operator-(const Fraction& fraction) {
    Fraction negatedFraction(-fraction.getTop(), fraction.getBottom());
    return negatedFraction;
}
Fraction operator*(  const Fraction& left,  const Fraction& right){
    Fraction multipliedFraction(left.getTop() * right.getTop(),left.getBottom() * right.getBottom());
    return multipliedFraction;
}

Fraction operator/( const Fraction& left, const Fraction& right){
    Fraction dividedFraction(left.getTop() * right.getBottom(),left.getBottom() * right.getTop());
    return dividedFraction;
}

Fraction operator+=( Fraction& left,  Fraction& right) {
    Fraction temp(left.getTop()*right.getBottom() + right.getTop() * left.getBottom(), left.getBottom() * right.getBottom());
    left = temp;
    return left;
}

FractionException::FractionException(const string &m) : message(m) {};

string FractionException::what() {
    return message;
}

int main () {
    Fraction test(5,2);
    Fraction test2(5,2);

    Fraction test3 = 2 - test;
    cout << test3;

}
