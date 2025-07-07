#ifndef TOKEN_H
#define TOKEN_H

// standard library headers
#include <type_traits>

template<typename T>
constexpr auto etov(T t) -> typename std::underlying_type<T>::type {
    return static_cast<typename std::underlying_type<T>::type>(t);
}

enum class TokenType {
    PLUS = '+',
    MINUS = '-',
    MULTIPLY = '*',
    DIVIDE = '/',
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
    double getValue() const;
    /**
     * Checks if the token is a number.
     * @return True if the token is of type NUMBER, false otherwise.
     */
    bool isNumber() const;
    /**
     * Checks if the token is an operator.
     * @return True if the token is an operator (PLUS, MINUS, MULTIPLY, DIVIDE), false otherwise.
     *         This method is useful for determining if the token can be used in an arithmetic operation
     */
    bool isOperator() const;
    /**
     * Checks if the token is a parenthesis.
     * @return True if the token is a left or right parenthesis, false otherwise.
     */
    bool isParenthesis() const;
    /**
     * Checks if the token is an end of execution token.
     * @return True if the token is of type QUIT, false otherwise.
     */
    bool isQuit() const;
    /**
     * Checks if the token is an end of expression token.
     * @return True if the token is of type END, false otherwise.
     *         This method is useful for determining if the token marks the end of an expression.
     */
    bool isEnd() const;
    /**
     * Returns the type of the token.
     * @return The TokenType of the token, which indicates its category (e.g., NUMBER, PLUS, MINUS, etc.).
     */
    TokenType getType() const;
    /**
     * Converts the token to a string representation.
     * @return A string representation of the token, useful for debugging or logging.
     */
    operator double() const { return value; }
};

#endif /* !TOKEN_H! */
