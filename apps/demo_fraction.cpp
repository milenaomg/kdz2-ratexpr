#include <iostream>
#include "ratexpr/fraction.hpp"

using namespace ratexpr;
using namespace std;

int main() {
    cout << Fraction(6, -8) << ' ';
    cout << Fraction(10, 4) << endl;
    cout << Fraction(1, 2) + Fraction(1, 3) << ' ';
    cout << Fraction(1, 2) - Fraction(1, 3) << ' ';
    cout << Fraction(1, 2) * Fraction(1, 3) << ' ';    
    cout << Fraction(1, 2) / Fraction(1, 3) << endl;
    cout << Fraction(1, 2) + 2u << ' ';
    cout << 2u + Fraction(1, 2) << endl;
    cout << Fraction(1, 2) - 2u << ' ';
    cout << 2u - Fraction(1, 2) << endl;
    cout << Fraction(1, 2) / 2u << ' ';
    cout << 2u / Fraction(1, 2) << endl;
    Fraction acc; 
    acc += Fraction(1, 2);
    acc += Fraction(1, 3);
    acc *= 6u;
    cout << acc << endl;
    cout << Fraction(1, 0) << ' ' << Fraction(1, 2) / 0u;
    return 0;
}