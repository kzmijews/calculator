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
#include "tstream.hpp"
// external library headers
#include "spdlog/spdlog.h"

namespace kz::calc::core {
    Token TokenStream::pop() {
        if (full) {
            full = false;
            return buffer;
        }
        char sign = 0;
        exprStream >> sign;
        switch (sign) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            case '.': {
                exprStream.putback(sign);
                double value;
                // it will read each digit until it reaches a non-digit character and return whole number
                exprStream >> value;
                return Token(TokenType::NUMBER, value);
            }
            case '+': case '-':
            case '*': case '/':
            case '(': case ')':
            case ';': case 'q':
                return Token(sign);
            default:
                return Token(TokenType::UNKNOWN);
        }
    }

    void TokenStream::push(Token token) {
        if (full) {
            spdlog::error(
                "TokenStream buffer is full, cannot push token: {}",
                static_cast<char>(etov(token.getType()))
            );
        } else {
            full = true;
            buffer = token;
        }
    }

    Token TokenStream::peek() {
        if (exprStream.peek()) {
            return Token(exprStream.peek());
        }
        return Token(TokenType::UNKNOWN);
    }

    void TokenStream::clear() {
        full = false;
        buffer = Token();
        exprStream.clear();
        // Clear the stringstream
        exprStream.str("");
        // Reset the stream position to the beginning
        exprStream.seekg(0);
    }
}