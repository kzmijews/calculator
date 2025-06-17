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
#include "tstream.hpp"

using namespace std;

double Calculator::expression() {
    double lvalue = term(); // Start with the first term
    while (true) {
        Token token = ts.pop();
        TokenType token_type = token.getType();
        if (token_type == TokenType::PLUS) {
            lvalue += term();
        } else if (token_type == TokenType::MINUS) {
            lvalue -= term();
        } else if (token_type == TokenType::END) {
            // End of expression, return the result
            break;
        } else if (token_type == TokenType::UNKNOWN) {
            // Handle unknown token
            throw InvalidExpression("Unknown token encountered: '" + to_string(etov(token_type)) + "'");
        } else {
            // If the token is not an operator, push it back to the stream
            // for further processing
            ts.push(token);
            break;
        }
    }
    return lvalue;
}

double Calculator::term() {
    double lvalue = primary();
    while(true) {
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
            break;
        }
    }
    return lvalue;
}

double Calculator::primary() {
    Token token = ts.pop();
    TokenType token_type = token.getType();
    if (token_type == TokenType::NUMBER) {
        return token.getValue();
    } else if (token_type == TokenType::LEFT_PAREN) {
        double lvalue = expression();
        // Expecting a right parenthesis
        token = ts.pop();
        token_type = token.getType();
        if (token_type != TokenType::RIGHT_PAREN) {
            throw InvalidExpression("Expected right parenthesis: ')'");
        }
        return lvalue;
    } else if (token_type == TokenType::MINUS) {
        return -primary();
    } else if (token_type == TokenType::QUIT) {
        throw EndOfExecution();
    } else if (token_type == TokenType::END) {
        throw EndOfExecution();
    }
    throw  InvalidExpression("Unexpected token: '" + to_string(etov(token.getType())) + "'");
}
