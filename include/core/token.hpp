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

#ifndef TOKEN_H
#define TOKEN_H

// standard library headers
#include <type_traits>

namespace kz::calc::core {
    template<typename T>
    constexpr auto etov(T t) -> typename std::underlying_type<T>::type {
        return static_cast<typename std::underlying_type<T>::type>(t);
    }

    enum class TokenType {
        PLUS = '+',
        MINUS = '-',
        MULTIPLY = '*',
        DIVIDE = '/',
        POWER = '^',
        FACTORIAL = '!',
        SQRT = 's',
        LEFT_PAREN = '(',
        RIGHT_PAREN = ')',
        END = ';',
        NUMBER = 'n',
        QUIT = 'q',
        UNKNOWN = '?'
    };

    class Token {
    private:
        TokenType type;
        double value;
    public:
        /**
         * Constructor for Token class.
         * Initializes a token with a specific sign or type and an optional value.
         * @param sign The character representing the token type (e.g., '+', '-', '*', '/', '(', ')', ';', 'q').
         *             If the sign is not recognized, the token type will be set to UNKNOWN.
         */
        Token(char sign);
        /**
         * Constructor for Token class.
         * Initializes a token with a specific opcode as a string.
         * @param opcode The string representing the token type (e.g., "sqrt", "pi").
         *               This constructor is used for special tokens that are not single characters.
         */
        Token(std::string opcode);
        /**
         * Constructor for Token class.
         * Initializes a token with a specific type and an optional value.
         * @param type The type of the token (e.g., NUMBER, PLUS, MINUS, etc.).
         * @param value The numeric value associated with the token, default is 0.0.
         */
        Token(TokenType type = TokenType::UNKNOWN, double value = 0.0);
        /**
         * Destructor for Token class.
         * Cleans up the token instance.
         */
        ~Token() = default;
        /**
         * Returns the value of the token.
         * @return The numeric value of the token, or 0.0 if the token is not a number.
         */
        double get_value() const;
        /**
         * Checks if the token is a number.
         * @return True if the token is of type NUMBER, false otherwise.
         */
        bool is_number() const;
        /**
         * Checks if the token is an operator.
         * @return True if the token is an operator (PLUS, MINUS, MULTIPLY, DIVIDE), false otherwise.
         *         This method is useful for determining if the token can be used in an arithmetic operation
         */
        bool is_operator() const;
        /**
         * Checks if the token is a parenthesis.
         * @return True if the token is a left or right parenthesis, false otherwise.
         */
        bool is_parenthesis() const;
        /**
         * Checks if the token is an end of execution token.
         * @return True if the token is of type QUIT, false otherwise.
         */
        bool is_quit() const;
        /**
         * Checks if the token is an end of expression token.
         * @return True if the token is of type END, false otherwise.
         *         This method is useful for determining if the token marks the end of an expression.
         */
        bool is_end() const;
        /**
         * Returns the type of the token.
         * @return The TokenType of the token, which indicates its category (e.g., NUMBER, PLUS, MINUS, etc.).
         */
        TokenType get_type() const;
        /**
         * Converts the token to a string representation.
         * @return A string representation of the token, useful for debugging or logging.
         */
        operator double() const { return value; }
    };
}

#endif /* !TOKEN_H! */
