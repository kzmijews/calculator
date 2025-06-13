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
    Token(char sign): type(static_cast<TokenType>(sign)), value(0.0) {
        if (isNumber()) {
            value = static_cast<double>(sign - '0');
        }
    }
    Token(TokenType type = TokenType::UNKNOWN, double value = 0.0): type(type), value(static_cast<double>(value)) {}
    double getValue() const { return value; }
    bool isNumber() const { return type == TokenType::NUMBER; }
    bool isOperator() const {
        bool isOperator = false;
        isOperator |= type == TokenType::PLUS;
        isOperator |= type == TokenType::MINUS;
        isOperator |= type == TokenType::MULTIPLY;
        isOperator |= type == TokenType::DIVIDE;
        return isOperator;
    }
    bool isParenthesis() const {
        return type == TokenType::LEFT_PAREN || type == TokenType::RIGHT_PAREN;
    }
    bool isQuit() const { return type == TokenType::QUIT; }
    bool isEnd() const { return type == TokenType::END; }
    operator double() const { return value; } // Allows implicit conversion to double
    TokenType getType() const { return type; }
};

class TokenStream {
private:
    bool full;
    Token buffer;
public:
    TokenStream(): full(false), buffer(Token()) {};
    Token pop();
    void push(Token token);
    Token peek() const;
    void clean();
};

#endif /* !TOKEN_H! */