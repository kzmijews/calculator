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

#include <gtest/gtest.h>
#include "calculator.hpp"
#include "exceptions.hpp"

namespace kz::calc::core {
    class CalculatorErrorHandlingTest : public ::testing::Test {
    protected:
        Calculator calculator;

        void SetUp() override {
            // Reset the calculator before each test
            calculator.reset();
        }
    };

    TEST_F(CalculatorErrorHandlingTest, InvalidExpression) {
        calculator << "1 + 2 *;"; // Invalid expression
        EXPECT_THROW(calculator.expression(), InvalidExpression);
        calculator.reset(); // Reset after exception
        calculator << "1 + 2 /;"; // Another invalid expression
        EXPECT_THROW(calculator.expression(), InvalidExpression);
        calculator.reset(); // Reset after exception
        calculator << "1 + ;"; // Incomplete expression
        EXPECT_THROW(calculator.expression(), InvalidExpression);
        calculator.reset(); // Reset after exception
        calculator << "1 + 2 -   ;"; // Incomplete expression
        EXPECT_THROW(calculator.expression(), InvalidExpression);
        calculator.reset(); // Reset after exception
        calculator << "1 + 2 * * 2;"; // Unexpected operator
        EXPECT_THROW(calculator.expression(), InvalidExpression);
        calculator.reset(); // Reset after exception
        calculator << "1 + 2 // 0;"; // Unexpected operator
        EXPECT_THROW(calculator.expression(), InvalidExpression);
        calculator.reset(); // Reset after exception
        calculator << "1 + 2 +   + 3;"; // Unexpected operator
        EXPECT_THROW(calculator.expression(), InvalidExpression);
        calculator.reset(); // Reset after exception
        calculator << "1 + 2 -- 3;"; // Valid epression
        EXPECT_NO_THROW(calculator.expression()); // Should not throw
        EXPECT_THROW(calculator.expression(), EndOfExpression); // Should throw on next call
    }

    TEST_F(CalculatorErrorHandlingTest, UnknownToken) {
        calculator << "1 + 2 @;"; // Unknown token
        EXPECT_THROW(calculator.expression(), InvalidExpression);
    }

    TEST_F(CalculatorErrorHandlingTest, DivisionByZero) {
        calculator << "1 / 0;"; // Division by zero
        EXPECT_THROW(calculator.expression(), InvalidExpression);
    }

    TEST_F(CalculatorErrorHandlingTest, EmptyExpression) {
        calculator << ";"; // Empty expression
        EXPECT_THROW(calculator.expression(), EndOfExpression);
    }

    TEST_F(CalculatorErrorHandlingTest, UnmatchedParentheses) {
        calculator << "(1 + 2;"; // Unmatched parentheses
        EXPECT_THROW(calculator.expression(), InvalidExpression);
    }

    TEST_F(CalculatorErrorHandlingTest, UnsupportedOperation) {
        calculator << "1 % 2;"; // Unsupported operation
        EXPECT_THROW(calculator.expression(), InvalidExpression);
    }

    TEST_F(CalculatorErrorHandlingTest, FactorialOfNegativeNumber) {
        calculator << "-5!;"; // Factorial of a negative number
        EXPECT_THROW(calculator.expression(), InvalidExpression);
    }

    TEST_F(CalculatorErrorHandlingTest, EndOfExpression) {
        calculator << "1 + 2;"; // Valid expression
        EXPECT_NO_THROW(calculator.expression()); // Should not throw
        EXPECT_THROW(calculator.expression(), EndOfExpression); // Should throw on next call
    }

    TEST_F(CalculatorErrorHandlingTest, EndOfExecution) {
        calculator << "q;"; // End of execution
        EXPECT_THROW(calculator.expression(), EndOfExecution); // Should throw on execution
    }

    TEST_F(CalculatorErrorHandlingTest, InvalidFunctionCall) {
        calculator << "invalid_function(1);"; // Invalid function call
        EXPECT_THROW(calculator.expression(), InvalidExpression);
    }

    TEST_F(CalculatorErrorHandlingTest, NestedInvalidExpression) {
        calculator << "(1 + 2) * (3 +;"; // Nested invalid expression
        EXPECT_THROW(calculator.expression(), InvalidExpression);
    }

    TEST_F(CalculatorErrorHandlingTest, MultipleErrorsInExpression) {
        calculator << "1 + 2 *; 3 / 0;"; // Multiple errors in one expression
        EXPECT_THROW(calculator.expression(), InvalidExpression); // Should throw for the first error
    }

    TEST_F(CalculatorErrorHandlingTest, InvalidCharacterInExpression) {
        calculator << "1 + 2 $;"; // Invalid character
        EXPECT_THROW(calculator.expression(), InvalidExpression);
    }
}