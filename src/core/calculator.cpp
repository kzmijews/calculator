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
#include <string>
// app headers
#include "token.hpp"
#include "exceptions.hpp"
#include "calculator.hpp"
#include "tstream.hpp"
#include "operations.hpp"
// external library headers
#include "spdlog/spdlog.h"

namespace kz::calc::core {
    void Calculator::validate_operand(const std::string& op_symbol) {
        Token next = ts.peek(true); // true = skip whitespace (your design)
        if (next.is_end()) {
            spdlog::trace("Unexpected end of expression after {} operator", op_symbol);
            throw InvalidExpression("Illegal token ';' after operator '" + op_symbol + "'");
        }
    }

    double Calculator::expression() {
        spdlog::trace("Starting expression evaluation.");
        double lvalue = term(); // Start with the first term
        while (true) {
            Token token = ts.pop();
            TokenType token_type = token.get_type();
            if (token_type == TokenType::PLUS) {
                spdlog::trace("exp: +");
                validate_operand("+");
                lvalue += term();
            } else if (token_type == TokenType::MINUS) {
                spdlog::trace("exp: -");
                validate_operand("-");
                lvalue -= term();
            } else if (token_type == TokenType::UNKNOWN) {
                // Handle unknown token
                throw InvalidExpression(
                    "Unknown token encountered: '" +
                    std::string(1, static_cast<char>(token_type)) + "'"
                );
            } else {
                // If the token is not a + or - operator, push it back to the stream
                // for further processing
                ts.push(token);
                break;
            }
        }
        spdlog::trace("Expression evaluation completed with result: {}", lvalue);
        return lvalue;
    }

    double Calculator::term() {
        double lvalue = power();
        while(true) {
            Token token = ts.pop();
            TokenType token_type = token.get_type();
            if (token_type == TokenType::MULTIPLY) {
                spdlog::trace("ter: *");
                validate_operand("*");
                lvalue *= power();
            } else if (token_type == TokenType::DIVIDE) {
                spdlog::trace("ter: /");
                validate_operand("/");
                double divisor = power();
                if (divisor == 0) {
                    throw InvalidExpression("Division by zero is not allowed.");
                }
                lvalue /= divisor;
            } else {
                // If the token is not a * or / operator, push it back to the stream
                // for the further processing
                ts.push(token);
                break;
            }
        }
        return lvalue;
    }

    double Calculator::power() {
        double lvalue = postfix();
        while (true) {
            Token token = ts.pop();
            TokenType token_type = token.get_type();
            if (token_type == TokenType::POWER) {
                spdlog::trace("pow: ^");
                validate_operand("^");
                lvalue = std::pow(lvalue, postfix());
            } else {
                // If the token is not a ^ operator, push it back to the stream
                // for further processing
                ts.push(token);
                break;
            }
        }
        return lvalue;
    }

    double Calculator::postfix() {
        double value = primary();
        while (true) {
            Token token = ts.pop();
            if (token.get_type() == TokenType::FACTORIAL) {
                spdlog::trace("post: !");
                value = Operations::factorial(value);
            } else {
                // If the token is not a ! operator, push it back to the stream
                // for further processing
                ts.push(token);
                break;
            }
        }
        return value;
    }

    double Calculator::primary() {
        Token token = ts.pop();
        TokenType token_type = token.get_type();
        if (token_type == TokenType::NUMBER) {
            spdlog::trace("pri: {}", token.get_value());
            return token.get_value();
        } else if (token_type == TokenType::LEFT_PAREN) {
            spdlog::trace("pri: (");
            double lvalue = expression();
            // Expecting a right parenthesis
            token = ts.pop();
            token_type = token.get_type();
            if (token_type != TokenType::RIGHT_PAREN) {
                throw InvalidExpression("Expected right parenthesis: ')'");
            }
            spdlog::trace("pri: )");
            return lvalue;
        } else if (token_type == TokenType::MINUS) {
            spdlog::trace("pri: -");
            return -primary();
        } else if (token_type == TokenType::SQRT) {
            spdlog::trace("pri: √");
            double value = primary();
            if (value < 0) {
                throw InvalidExpression("Square root of negative number is not allowed.");
            }
            return std::sqrt(value);
        } else if (token_type == TokenType::QUIT) {
            throw EndOfExecution();
        } else if (token_type == TokenType::END) {
            throw EndOfExpression();
        }
        throw InvalidExpression(
            "Unexpected token: '" + std::string(1, static_cast<char>(etov(token_type))) + "'"
        );
    }
} // namespace kz::calc::core
