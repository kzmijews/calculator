#include <iostream>
#include "token.hpp"
#include "calculator.hpp"

using namespace std;

int main() {
    cout << "Calculator" << endl;
    TokenStream ts;
    Calculator calculator;
    cout << "Enter expression (or 'q' to quit): ";
    double value = calculator.expression();
    cout << "= " << value << endl;
    return 0;
}