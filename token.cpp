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
            cin >> value;
            return Token('8', value); // Assuming '8' is the kind for numbers, todo: change it to enum
        }
        case '+': case '-':
        case '*': case '/':
        case '(': case ')':
            return Token(sign);
        default:
            cerr << "unknown token: " << sign << endl;
            return Token();
    }
}

void TokenStream::push(Token token) {
    // todo: stubbed
}