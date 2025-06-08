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

using namespace std;


class Calculator {
    public:
        int calculate(int a, int b);
};

int Calculator::calculate(int a, int b) {
    return a + b;
}


int main() {
    cout << "Hello world" << endl;
    cout << "add(2, 3) = " << Calculator().calculate(2, 3) << endl;
    return 0;
}