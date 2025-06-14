#include <iostream>
#include "token.hpp"

using namespace std;

Token::Token(char sign): type(static_cast<TokenType>(sign)), value(0.0) {
    if (isNumber()) {
        value = static_cast<double>(sign - '0');
    }
}

Token::Token(TokenType type, double value): type(type), value(static_cast<double>(value)) {
}

double Token::getValue() const {
    return value;
}

bool Token::isNumber() const {
    return type == TokenType::NUMBER;
}

bool Token::isOperator() const {
    bool isOperator = false;
    isOperator |= type == TokenType::PLUS;
    isOperator |= type == TokenType::MINUS;
    isOperator |= type == TokenType::MULTIPLY;
    isOperator |= type == TokenType::DIVIDE;
    return isOperator;
}

bool Token::isParenthesis() const {
    return type == TokenType::LEFT_PAREN || type == TokenType::RIGHT_PAREN;
}

bool Token::isQuit() const {
    return type == TokenType::QUIT;
}

bool Token::isEnd() const {
    return type == TokenType::END; 
}

TokenType Token::getType() const {
    return type;
}
