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

namespace kz::calc::core {
    class CalculatorComplexTest : public ::testing::Test {
    protected:
        Calculator calculator;

        void SetUp() override {
            // Reset the calculator before each test
            calculator.reset();
        }
    };

    TEST_F(CalculatorComplexTest, OperationOrderExpression) {
        calculator << "2.0 + 3.0 * 2.0 ^ 2.0 - 5.0 / 5.0 - 1.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 12.0);
    }

    TEST_F(CalculatorComplexTest, BracketSupportExpression) {
        calculator << "(2.0 + 3.0) * (4.0 - 5.0) / (5.0 - 1.0);";
        EXPECT_DOUBLE_EQ(calculator.expression(), -1.25);
    }

    TEST_F(CalculatorComplexTest, NestedBracketsExpression) {
        calculator << "(2.0 + 3.0) * ((4.0 - 5.0) / (5.0 - 1.0));";
        EXPECT_DOUBLE_EQ(calculator.expression(), -1.25);
    }

    TEST_F(CalculatorComplexTest, NegativesExpression) {
        calculator << "2.0 + -(3.0 * -4.0) - (5.0 / -5.0);";
        EXPECT_DOUBLE_EQ(calculator.expression(), 15.0);
    }

    TEST_F(CalculatorComplexTest, SeqAddExpression) {
        calculator << "1 + 2 + 3 + 4;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 10.0);
    }

    TEST_F(CalculatorComplexTest, SeqSubExpression) {
        calculator << "10 - 1 - 2 - 3;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 4.0);
    }

    TEST_F(CalculatorComplexTest, SeqMulExpression) {
        calculator << "2 * 3 * 4;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 24.0);
    }

    TEST_F(CalculatorComplexTest, SeqDivExpression) {
        calculator << "100 / 2 / 5;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 10.0);
    }

    TEST_F(CalculatorComplexTest, SeqPowExpression) {
        calculator << "2 ^ 2 ^ 2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 16.0);
    }
} // namespace kz::calc::core