#include <iostream>
#include "ratexpr/expression.hpp"
#include "ratexpr/fraction.hpp"

using namespace ratexpr;
using namespace std;

int main() {
    auto res = make_unique<Mul>( 
        make_unique<Add> (
            make_unique<Const>(Fraction(1, 2)), make_unique<Const>(Fraction(1, 3)))
        , make_unique<Sub> (
            make_unique<Const>(Fraction(3, 1)), make_unique<Const>(Fraction(1, 4))
        )
    );
    cout << res->evaluate() << endl;

    auto res2 = make_unique<Negative>( make_unique<Const>(Fraction(2, 3)));
    cout << res2->evaluate() << endl;
    return 0;
};
