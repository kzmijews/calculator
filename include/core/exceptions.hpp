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

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

// standard library headers
#include <stdexcept>
#include <string>

using namespace std;

class InvalidExpression : public std::exception {
private:
    string message;
public:
    /**
     * Constructor for InvalidExpression exception.
     * Initializes the exception with a specific message.
     * @param msg The message describing the invalid expression.
     */
    explicit InvalidExpression(const string& msg);
    /**
     * Destructor for InvalidExpression exception.
     * Cleans up the exception instance.
     */
    virtual ~InvalidExpression() = default;
    /**
     * Returns the error message associated with the exception.
     * @return A C-style string containing the error message.
     */
    const char* what() const noexcept override;
};

class EndOfExpression : public std::exception {
public:
    /**
     * Default constructor for EndOfExpression exception.
     * This exception is thrown to indicate the end of an expression.
     */
    explicit EndOfExpression() = default;
    /**
     * Destructor for EndOfExpression exception.
     * Cleans up the exception instance.
     */
    virtual ~EndOfExpression() = default;
    /**
     * Returns a message indicating the end of an expression.
     * @return A C-style string containing the end of expression message.
     */
    const char* what() const noexcept override {
        return "End of expression";
    }
};

class EndOfExecution : public std::exception {
public:
    /**
     * Default constructor for EndOfExecution exception.
     * This exception is thrown to indicate the end of execution of the calculator.
     */
    explicit EndOfExecution() = default;
    /**
     * Destructor for EndOfExecution exception.
     * Cleans up the exception instance.
     */
    virtual ~EndOfExecution() = default;
    /**
     * Returns a message indicating the end of execution.
     * @return A C-style string containing the end of execution message.
     */
    const char* what() const noexcept override {
        return "End of execution";
    }
};

#endif /* !EXCEPTIONS_H! */
