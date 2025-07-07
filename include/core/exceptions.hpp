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
