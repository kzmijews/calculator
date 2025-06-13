#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

using namespace std;

class InvalidExpression : public std::exception {
private:
    string message;
public:
    /**
     * Constructor with a default message
     * Allows the user to specify a custom message
     * explicite - prevents implicit conversions
     * @param msg Custom error message
     */ 
    InvalidExpression(const string& msg);
    virtual ~InvalidExpression() = default;
    const char* what() const noexcept override;
};

class EndOfExpression : public std::exception {
public:
    EndOfExpression() = default;
    virtual ~EndOfExpression() = default;
    const char* what() const noexcept override {
        return "End of expression";
    }
};

class EndOfExecution : public std::exception {
public:
    EndOfExecution() = default;
    virtual ~EndOfExecution() = default;
    const char* what() const noexcept override {
        return "End of execution";
    }
};

#endif /* !EXCEPTIONS_H! */