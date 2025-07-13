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

// standard library headers
#include <iostream>
// app headers
#include "token.hpp"

Token::Token(char sign): type(static_cast<TokenType>(sign)), value(0.0) {
    if (isNumber()) {
        value = static_cast<double>(sign - '0');
    }
}

Token::Token(TokenType type, double value): type(type), value(static_cast<double>(value)) {
}

double Token::getValue() const {
    return value;
}

bool Token::isNumber() const {
    return type == TokenType::NUMBER;
}

bool Token::isOperator() const {
    bool isOperator = false;
    isOperator |= type == TokenType::PLUS;
    isOperator |= type == TokenType::MINUS;
    isOperator |= type == TokenType::MULTIPLY;
    isOperator |= type == TokenType::DIVIDE;
    return isOperator;
}

bool Token::isParenthesis() const {
    return type == TokenType::LEFT_PAREN || type == TokenType::RIGHT_PAREN;
}

bool Token::isQuit() const {
    return type == TokenType::QUIT;
}

bool Token::isEnd() const {
    return type == TokenType::END;
}

TokenType Token::getType() const {
    return type;
}
