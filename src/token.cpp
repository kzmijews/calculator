#include <iostream>
#include "token.hpp"

using namespace std;


/**
 * TokenStream class implementation.
 * This class is responsible for reading tokens from the input stream and managing a buffer for tokens.
 * It can pop a token from the input or push a token back into the buffer.
 * TODO: Implement the push method to handle token buffering correctly.
 * TODO: Handle errors and unexpected input more gracefully.
 * TODO: Consider using a more robust input method for token parsing, such as regex or a lexer.
 * TODO: Add support for more token types and operators as needed.
 * TODO: Add enum types for token kinds to improve readability and maintainability.
 * TODO: Split token reading logic from token parsing logic for better separation of concerns.
 */
Token TokenStream::pop() {
    if (full) {
        full = false;
        return buffer;
    }
    char sign = 0;
    cin >> sign;
    switch (sign) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.': {
            cin.putback(sign);
            double value;
            cin >> value; // it will read each digit until it reaches a non-digit character and return whole number
            return Token(TokenType::NUMBER, value); // Assuming '8' is the kind for numbers, todo: change it to enum
        }
        case '+': case '-':
        case '*': case '/':
        case '(': case ')':
        case ';': case 'q':
            return Token(sign);
        default:
            cerr << "unknown token: " << sign << endl;
            return Token();
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

Token TokenStream::peek() const {
    if (cin.peek()) {
        return Token(cin.get());
    }
    return Token(TokenType::UNKNOWN);
}

void TokenStream::clean() {
    full = false; // Clear the buffer
    buffer = Token(); // Reset the buffer token
}