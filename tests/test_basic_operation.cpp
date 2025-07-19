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
    class CalculatorTest : public ::testing::Test {
    protected:
        Calculator calculator;

        void SetUp() override {
            // Reset the calculator before each test
            calculator.reset();
        }
    };

    TEST_F(CalculatorTest, SimpleAddition) {
        calculator << "2.0 + 3.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 5.0);
    }

    TEST_F(CalculatorTest, SimpleSubtraction) {
        calculator << "5.0 - 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 3.0);
    }

    TEST_F(CalculatorTest, SimpleMultiplication) {
        calculator << "4.0 * 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 8.0);
    }

    TEST_F(CalculatorTest, SimpleDivision) {
        calculator << "8.0 / 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 4.0);
    }

    TEST_F(CalculatorTest, ComplexExpression) {
        calculator << "2.0 + 3.0 * 4.0 - 5.0 / 5.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 13.0);
    }

} // namespace kz::calc::core
