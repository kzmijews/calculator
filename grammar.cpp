#include "grammar.hpp"
#include "token.hpp"
#include <iostream>

using namespace std;

double Grammar::expression() {
    double lvalue = term();
    TokenStream ts;
    Token token = ts.pop();
    while (token.getKind() == '+' || token.getKind() == '-') {
        if (token.getKind() == '+') {
            lvalue += term();
        } else if (token.getKind() == '-') {
            lvalue -= term();
        }
        token = ts.pop(); // Get the next token
    }
    ts.push(token); // Push back the last token for further processing
    return lvalue;
}

double Grammar::term() {
    double lvalue = primary();
    TokenStream ts;
    Token token = ts.pop();
    while (token.getKind() == '*' || token.getKind() == '/') {
        if (token.getKind() == '*') {
            lvalue *= primary();
        } else if (token.getKind() == '/') {
            double divisor = primary();
            if (divisor == 0) {
                cerr << "Error: division by zero" << endl;
                exit(1);
            }
            lvalue /= divisor;
        }
        token = ts.pop(); // Get the next token
    }
    ts.push(token); // Push back the last token for further processing
    return lvalue;
}

double Grammar::primary() {
    TokenStream ts;
    Token token = ts.pop();
    switch (token.getKind()) {
        case '8': // Number
            return token.getValue();
        case '(': // Left parenthesis
            double lvalue = expression();
            token = ts.pop(); // Expecting a right parenthesis
            if (token.getKind() != ')') {
                cerr << "Error: expected ')'" << endl;
                exit(1);
            }
            return lvalue;
        case '-': // Unary minus
            return -primary();
        default:
            cerr << "Error: unexpected token '" << token.getKind() << "'" << endl;
            exit(1);
    }
}