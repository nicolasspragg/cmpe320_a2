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

    if(topNum < 0 && bottomNum <0) {
        topNum = -topNum;
    }
    if (bottomNum < 0) {
        topNum = -topNum;
    }

    for (int i = bottomNum * topNum; i >1; i--) {
        if(bottomNum % i == 0 && topNum % i == 0) {
            bottomNum /= i;
            topNum /= i;
        }

    }






}

int Fraction::gcd(int n, int m) {
    if(m <= n && n%m == 0) {
        return m;
    } else if(n < m) {
        return gcd(m,n);
    } else {
        return gcd(m,n%m);
    }
}

int main () {
    cout << "hello";
}
