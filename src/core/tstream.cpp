// standard library headers
#include <iostream>
// app headers
#include "token.hpp"
#include "tstream.hpp"

using namespace std;

Token TokenStream::pop() {
    if (full) {
        full = false;
        return buffer;
    }
    char sign = 0;
    exprStream >> sign;
    switch (sign) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.': {
            exprStream.putback(sign);
            double value;
            // it will read each digit until it reaches a non-digit character and return whole number
            exprStream >> value;
            return Token(TokenType::NUMBER, value);
        }
        case '+': case '-':
        case '*': case '/':
        case '(': case ')':
        case ';': case 'q':
            return Token(sign);
        default:
            return Token(TokenType::UNKNOWN);
    }
}

void TokenStream::push(Token token) {
    if (full) {
        cerr << "TokenStream buffer is full, cannot push token." << endl;
    } else {
        full = true;
        buffer = token;
    }
}

Token TokenStream::peek() {
    if (exprStream.peek()) {
        return Token(exprStream.peek());
    }
    return Token(TokenType::UNKNOWN);
}

void TokenStream::clear() {
    full = false;
    buffer = Token();
    exprStream.clear();
    // Clear the stringstream
    exprStream.str("");
    // Reset the stream position to the beginning
    exprStream.seekg(0);
}
