#ifndef TOKEN_H
#define TOKEN_H

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
    Token(char sign);
    Token(TokenType type = TokenType::UNKNOWN, double value = 0.0);
    double getValue() const;
    bool isNumber() const;
    bool isOperator() const;
    bool isParenthesis() const;
    bool isQuit() const;
    bool isEnd() const;
    TokenType getType() const;
    operator double() const { return value; } // Allows implicit conversion to double
};

#endif /* !TOKEN_H! */