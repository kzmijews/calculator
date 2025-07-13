/**
 * Copyright © 2025 Karol Zmijewski

 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the “Software”), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,

 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
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
