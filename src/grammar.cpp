#include "grammar.hpp"
#include "token.hpp"
#include <iostream>

using namespace std;

double Grammar::expression() {
    double lvalue = term();
    TokenStream ts;
    Token token = ts.pop();
    char token_kind = token.getKind();
    while (token_kind == '+' || token_kind == '-') {
        if (token_kind == '+') {
            lvalue += term();
        } else if (token_kind == '-') {
            lvalue -= term();
        }
        // Get the next token
        token = ts.pop();
    }
    // Push back the last token for further processing
    ts.push(token);
    return lvalue;
}

double Grammar::term() {
    double lvalue = primary();
    TokenStream ts;
    Token token = ts.pop();
    char token_kind = token.getKind();
    while (token_kind == '*' || token_kind == '/') {
        if (token_kind == '*') {
            lvalue *= primary();
        } else if (token_kind == '/') {
            double divisor = primary();
            if (divisor == 0) {
                cerr << "Error: division by zero" << endl;
                exit(1);
            }
            lvalue /= divisor;
        }
        // Get the next token
        token = ts.pop();
    }
    // Push back the last token for further processing
    ts.push(token);
    return lvalue;
}

double Grammar::primary() {
    TokenStream ts;
    Token token = ts.pop();
    switch (token.getKind()) {
        // Number
        case '8':
            return token.getValue();
        // Left parenthesiss
        case '(': {
            double lvalue = expression();
            // Expecting a right parenthesis
            token = ts.pop();
            if (token.getKind() != ')') {
                cerr << "Error: expected ')'" << endl;
                return 0.0; // Return 0.0 for error
            }
            return lvalue;
        }
        // Unary minus
        case '-':
            return -primary();
        default:
            cerr << "Error: unexpected token '" << token.getKind() << "'" << endl;
            return 0.0; // Return 0.0 for unexpected tokens
    }
}