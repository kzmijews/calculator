#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "token.hpp"
#include "tstream.hpp"

class Calculator {
private:
    TokenStream ts;
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
     * @throws InvalidExpression If the expression is invalid or unsupported.
     * @throws EndOfExecution If the end of execution is reached (e.g., user inputs 'q').
     * @throws std::runtime_error If an unexpected error occurs during evaluation.
     * @note The expression must be properly formatted and terminated with a semicolon (';').
     */
    double expression();
    /**
     * Parses a term from the token stream.
     * A term is defined as a factor followed by zero or more multiplication or division operations.
     * @return The result of the term as a double.
     * @throws InvalidExpression If the term is invalid or unsupported.
     */
    double term();
    /**
     * Parses a factor from the token stream.
     * A factor can be a number, a parenthesis-enclosed expression, or a function like square root.
     * @return The result of the factor as a double.
     * @throws InvalidExpression If the factor is invalid or unsupported.
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

#endif /* !CALCULATOR_H! */
