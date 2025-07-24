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
#include <math.h>
// app headers
#include "token.hpp"

namespace kz::calc::core {
    Token::Token(char sign): type(static_cast<TokenType>(sign)), value(0.0) {
        if (is_number()) {
            value = static_cast<double>(sign - '0');
        }
    }

    Token::Token(std::string opcode) {
        if (opcode == "sqrt") {
            type = TokenType::SQRT;
            value = 0.0; // No value for sqrt token
        } else if (opcode == "pi") {
            type = TokenType::NUMBER;
            value = M_PI; // Set value to pi
        } else {
            type = TokenType::UNKNOWN;
            value = 0.0; // Default value for unknown tokens
        }
    }

    Token::Token(TokenType type, double value): type(type), value(static_cast<double>(value)) {
    }

    double Token::get_value() const {
        return value;
    }

    bool Token::is_number() const {
        return type == TokenType::NUMBER;
    }

    bool Token::is_operator() const {
        bool is_operator = false;
        is_operator |= type == TokenType::PLUS;
        is_operator |= type == TokenType::MINUS;
        is_operator |= type == TokenType::MULTIPLY;
        is_operator |= type == TokenType::DIVIDE;
        is_operator |= type == TokenType::POWER;
        is_operator |= type == TokenType::SQRT;
        is_operator |= type == TokenType::FACTORIAL;
        return is_operator;
    }

    bool Token::is_parenthesis() const {
        return type == TokenType::LEFT_PAREN || type == TokenType::RIGHT_PAREN;
    }

    bool Token::is_quit() const {
        return type == TokenType::QUIT;
    }

    bool Token::is_end() const {
        return type == TokenType::END;
    }

    TokenType Token::get_type() const {
        return type;
    }
}
