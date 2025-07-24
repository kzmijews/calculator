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

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "token.hpp"
#include "tstream.hpp"

namespace kz::calc::core {
    class Calculator {
    private:
        TokenStream ts;
        void validate_operand(const std::string& op_symbol);
    public:
        /**
         * Constructor for the Calculator class.
         * Initializes the calculator with an empty token stream.
         */
        Calculator() {};
        /**
         * Destructor for the Calculator class.
         * Cleans up the calculator instance.
         * This destructor is defaulted and does not perform any additional cleanup.
         */
        ~Calculator() = default;
        /**
         * Evaluates an expression from the token stream.
         * This method processes the input expression and returns the result as a double.
         * It handles various operations such as addition, subtraction, multiplication, division,
         * and parentheses. It also supports functions like square root.
         * @return The result of the evaluated expression as a double.
         * @throws kz::calc::core::InvalidExpression If the expression is invalid or unsupported.
         * @throws kz::calc::core::EndOfExecution If the end of execution is reached (e.g., user inputs 'q').
         * @throws std::runtime_error If an unexpected error occurs during evaluation.
         * @note The expression must be properly formatted and terminated with a semicolon (';').
         */
        double expression();
        /**
         * Parse power operation from the token stream.
         * This method processes the power operation (^) in the expression.
         * It handles the exponentiation operation and returns the result as a double.
         * @return The result of the power operation as a double.
         * @throws kz::calc::core::InvalidExpression If the power operation is invalid or
         */
        double power();
        /**
         * Parses a postfix operation from the token stream.
         * This method processes the postfix operation (e.g., factorial) in the expression.
         * It handles the postfix operation and returns the result as a double.
         * @return The result of the postfix operation as a double.
         * @throws kz::calc::core::InvalidExpression If the postfix operation is invalid or
         * unsupported.
         */
        double postfix();
        /**
         * Parses a term from the token stream.
         * A term is defined as a factor followed by zero or more multiplication or division operations.
         * @return The result of the term as a double.
         * @throws kz::calc::core::InvalidExpression If the term is invalid or unsupported.
         */
        double term();
        /**
         * Parses a factor from the token stream.
         * A factor can be a number, a parenthesis-enclosed expression, or a function like square root.
         * @return The result of the factor as a double.
         * @throws kz::calc::core::InvalidExpression If the factor is invalid or unsupported.
         */
        double primary();
        /**
         * Overloaded operator to insert an expression into the token stream.
         * This allows for easy insertion of expressions into the calculator.
         * @param expr The expression to insert into the token stream.
         * @return Reference to the current Calculator instance.
         */
        Calculator& operator<<(const std::string& expr) {
            ts << expr;
            return *this;
        };
        /**
         * Resets the calculator state by clearing the token stream.
         * This method clears the internal token stream and resets the buffer state.
         * It is useful for starting a new calculation or clearing the current state.
         */
        void reset() {
            ts.clear();
        };
    };
}

#endif /* !CALCULATOR_H! */
