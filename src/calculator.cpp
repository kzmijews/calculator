/**
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
#include <string>
#include "token.hpp"
#include "exceptions.hpp"
#include "calculator.hpp"

using namespace std;


Calculator::Calculator() {
    ts = TokenStream();
}

double Calculator::expression() {
    double lvalue = term();
    Token token = ts.pop();
    TokenType token_kind = token.getType();
    if (token_kind == TokenType::PLUS) {
        lvalue += term();
    } else if (token_kind == TokenType::MINUS) {
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
    Token token = ts.pop();
    TokenType token_kind = token.getType();
    if (token_kind == TokenType::MULTIPLY) {
        lvalue *= primary();
    } else if (token_kind == TokenType::DIVIDE) {
        double divisor = primary();
        if (divisor == 0) {
            throw InvalidExpression("Division by zero is not allowed.");
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
    Token token = ts.pop();
    auto token_value = etov(token.getType());
    switch (token_value) {
        // Number
        case etov(TokenType::NUMBER):
            return token.getValue();
        // Left parenthesiss
        case etov(TokenType::LEFT_PAREN): {
            double lvalue = expression();
            // Expecting a right parenthesis
            token = ts.pop();
            if (token.getType() != TokenType::RIGHT_PAREN) {
                throw InvalidExpression("Expected right parenthesis: ')'");
            }
            return lvalue;
        }
        // Unary minus
        case etov(TokenType::MINUS):
            return -primary();
        case etov(TokenType::END):
            throw EndOfExpression(); // End of expression, no more tokens to process
        case etov(TokenType::QUIT):
            throw EndOfExecution(); // Quit command, end the expression processing
        default:
            throw  InvalidExpression("Unexpected token: '" + to_string(token_value) + "'");
    }
}
