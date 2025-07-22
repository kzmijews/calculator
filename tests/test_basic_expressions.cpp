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
    class CalculatorBasicTest : public ::testing::Test {
    protected:
        Calculator calculator;

        void SetUp() override {
            // Reset the calculator before each test
            calculator.reset();
        }
    };

    // Read number - basic tests
    TEST_F(CalculatorBasicTest, SimpleNumberRead) {
        calculator << "01234.01234;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 1234.01234);
    }

    // Addition - basic tests
    TEST_F(CalculatorBasicTest, SimpleDoubleAddition) {
        calculator << "1.0 + 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 3.0);
    }

    TEST_F(CalculatorBasicTest, SimpleFractionAddition) {
        calculator << "1.1 + 2.2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 3.3);
    }

    TEST_F(CalculatorBasicTest, SimpleIntAddition) {
        calculator << "1 + 2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 3.0);
    }

    TEST_F(CalculatorBasicTest, SimpleMixedAddition) {
        calculator << "1 + 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 3.0);
    }

    TEST_F(CalculatorBasicTest, SimpleNegAddition) {
        calculator << "-1.0 + 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 1.0);
    }

    // Subtraction - basic tests
    TEST_F(CalculatorBasicTest, SimpleDoubleSubtraction) {
        calculator << "3.0 - 1.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 2.0);
    }

    TEST_F(CalculatorBasicTest, SimpleFractionSubtraction) {
        calculator << "3.3 - 1.1;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 2.2);
    }

    TEST_F(CalculatorBasicTest, SimpleIntSubtraction) {
        calculator << "3 - 1;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 2.0);
    }

    TEST_F(CalculatorBasicTest, SimpleMixedSubtraction) {
        calculator << "3 - 1.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 2.0);
    }

    TEST_F(CalculatorBasicTest, SimpleNegSubtraction) {
        calculator << "-3.0 - 1.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), -4.0);
    }

    // Multiplication - basic tests
    TEST_F(CalculatorBasicTest, SimpleDoubleMultiplication) {
        calculator << "3.0 * 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 6.0);
    }

    TEST_F(CalculatorBasicTest, SimpleFractionMultiplication) {
        calculator << "3.3 * 2.2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 7.26);
    }

    TEST_F(CalculatorBasicTest, SimpleIntMultiplication) {
        calculator << "3 * 2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 6.0);
    }

    TEST_F(CalculatorBasicTest, SimpleMixedMultiplication) {
        calculator << "3.0 * 2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 6.0);
    }

    TEST_F(CalculatorBasicTest, SimpleNegMultiplication) {
        calculator << "-3 * 2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), -6.0);
    }

    // Division - basic tests
    TEST_F(CalculatorBasicTest, SimpleDoubleDivision) {
        calculator << "6.0 / 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 3.0);
    }

    TEST_F(CalculatorBasicTest, SimpleFractionDivision) {
        calculator << "3.3 / 2.2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 1.5);
    }

    TEST_F(CalculatorBasicTest, SimpleIntDivision) {
        calculator << "6 / 2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 3.0);
    }

    TEST_F(CalculatorBasicTest, SimpleMixedDivision) {
        calculator << "3.3 / 2;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 1.65);
    }

    TEST_F(CalculatorBasicTest, SimpleNegDivision) {
        calculator << "-3.0 / 2.0;";
        EXPECT_DOUBLE_EQ(calculator.expression(), -1.5);
    }

    // Power - basic tests
    TEST_F(CalculatorBasicTest, SimplePower) {
        calculator << "2 ^ 3;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 8.0);
    }

     TEST_F(CalculatorBasicTest, SimpleNegPower) {
        calculator << "-2 ^ -3;";
        EXPECT_DOUBLE_EQ(calculator.expression(), -0.125);
     }

     // Square root - basic tests
    TEST_F(CalculatorBasicTest, SimpleSqrt) {
        calculator << "sqrt 4;";
        EXPECT_DOUBLE_EQ(calculator.expression(), 2.0);
    }
} // namespace kz::calc::core
