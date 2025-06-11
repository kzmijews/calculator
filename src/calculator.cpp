/**
 * @file main.cpp
 * @brief Main file for the calculator project.
 * @version 0.1
 * @date 2025-06-07
 * Context-Free Gramar (CFG) example. Set of rules defining correct expression and instruction syntax.
 * Based on BNF (Backus-Naur Form) - notation system for defining the syntax of programming languages
 * and other formal languages. It's a meta-syntax for context-free grammars, providing a precise way
 * to outline the rules od a language's structure. Used to describe document formats, instruction sets
 * and communication protocols. There are also some variations such as EBNF (Extended Backus-Naur Form),
 * and ABNF (Augmented Backus-Naur Form). Consist of three core components:
 * - non-terminal symbols: categories or viarables that can be replaced, represented by names enclosed
 *   in angle brackets (e.g., <expression>, <statement>).
 * - terminal symbols: fixed elements such as keywords, punctuation.
 * - derivation rules: define how non-terminal symbols can be replaced with terminal symbols or other
 *
 * Simplified BNF grammar:
 * expression:
 *     term
 *     expression + term
 *     expression - term
 *
 * term:
 *     primary
 *     primary * term
 *     primary / term
 *
 * primary:
 *     number
 *     ( expression )
 *     - primary
 */

#include <iostream>
#include "token.hpp"
#include "calculator.hpp"

using namespace std;


Calculator::Calculator() {
    ts = TokenStream();
}

double Calculator::expression() {
    double lvalue = term();
    Token token = ts.pop();
    char token_kind = token.getKind();
    if (token_kind == '+') {
        lvalue += term();
    } else if (token_kind == '-') {
        lvalue -= term();
    } else {
        // If the token is not an operator, push it back to the stream
        // for further processing
        ts.push(token);
    }
    return lvalue;
}

double Calculator::term() {
    double lvalue = primary();
    //TokenStream ts;
    Token token = ts.pop();
    char token_kind = token.getKind();
    if (token_kind == '*') {
        lvalue *= primary();
    } else if (token_kind == '/') {
        double divisor = primary();
        if (divisor == 0) {
            cerr << "Error: division by zero" << endl;
            exit(1);
        }
        lvalue /= divisor;
    } else {
        // If the token is not an operator, push it back to the stream
        // for the further processing
        ts.push(token);
    }
    return lvalue;
}

double Calculator::primary() {
    //TokenStream ts;
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
