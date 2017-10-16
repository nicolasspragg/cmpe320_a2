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

ostream& operator << (ostream& output,  const Fraction& frac) {
    return output << frac.getTop() << "/" << frac.getBottom() << endl;
}

istream& operator>>(istream &input, Fraction &frac) {
    int top;
    int bottom;
    char symbolChecker;
    input >> top;

    if(top == 0) {
        frac = Fraction();
        return input;
    }

    symbolChecker = input.peek();
    if(symbolChecker == '/'){
        input.get();
        input >> bottom;
    }

    frac = Fraction(top,bottom);
    return input;


}
Fraction operator+( const Fraction& left,  const Fraction& right) {
    Fraction fractionAfterAdding(left.getTop() * right.getBottom() + left.getBottom() * right.getTop(), left.getBottom() * right.getBottom());
    return fractionAfterAdding;
}

Fraction operator-( const  Fraction& left, const Fraction& right) {
    Fraction fractionAfterAdding(left.getTop() * right.getBottom() - left.getBottom() * right.getTop(), left.getBottom() * right.getBottom());
    return fractionAfterAdding;
}

Fraction &Fraction::operator-() {
    topNum *= -1;
    return *this;
}
Fraction operator*(  const Fraction& left,  const Fraction& right){
    Fraction multipliedFraction(left.getTop() * right.getTop(),left.getBottom() * right.getBottom());
    return multipliedFraction;
}

Fraction operator/( const Fraction& left, const Fraction& right){
    Fraction dividedFraction(left.getTop() * right.getBottom(),left.getBottom() * right.getTop());
    return dividedFraction;
}

Fraction operator+=( Fraction& left, Fraction& right) {
    Fraction temp(left.getTop()*right.getBottom() + right.getTop() * left.getBottom(), left.getBottom() * right.getBottom());
    left = temp;
    return left;
}

Fraction &Fraction::operator++() {
    topNum += bottomNum;
    return *this;
}

Fraction &Fraction::operator++(int) {
    Fraction temp(*this);
    ++*this;
    return temp;

}

bool operator > (const Fraction& left, const Fraction& right){
    float lhsRes = float(left.getTop()/ left.getBottom());
    float rhsRes = float(right.getTop()/ right.getBottom());
    if (lhsRes > rhsRes) {
        return true;
    } else {
        return false;
    }
}

bool operator < (const Fraction& left, const Fraction& right){
    float lhsRes = float(left.getTop()/ left.getBottom());
    float rhsRes = float(right.getTop()/ right.getBottom());
    if (lhsRes < rhsRes) {
        return true;
    } else {
        return false;
    }
}

bool operator >=(const Fraction& left, const Fraction& right) {
    if((left > right)||(left == right)) {
        return true;
    } else {
        return false;
    }

}

bool operator <=(const Fraction& left, const Fraction& right) {
    if((left < right)||(left == right)) {
        return true;
    } else {
        return false;
    }

}

bool operator==(const Fraction& left, const Fraction& right) {
    if(left.getTop() == right.getTop() && left.getBottom() == right.getBottom()) {
        return true;
    } else {
        return false;
    }

}

bool operator!=(const Fraction& left, const Fraction& right){
    if(left.getTop() != right.getTop() || left.getBottom() != right.getBottom()) {
        return true;
    } else {
        return false;
    }
}

FractionException::FractionException(const string &m) : message(m) {};

string FractionException::what() {
    return message;
}

int main () {

    // Test input, exception and +=:
    Fraction sum(0);
    Fraction fin;
    cout << "\nSumming fractions. Enter fractions as \"1/2\" or just enter a single integer." << endl;
    cout << "Enter zero to end the summation:" << endl;
    do {
        cout << "Enter a fraction to add to sum: ";
        try {
            cin >> fin;
            sum += fin;
        } catch (FractionException &e) {
            cout << e.what() << endl;
        }
    } while (fin != 0);
    cout << "Sum is: " << sum << endl;


}
