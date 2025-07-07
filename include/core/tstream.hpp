#ifndef CLISTREAM_H
#define CLISTREAM_H

// standard library headers
#include <sstream>
// app headers
#include "tstream.hpp"
#include "token.hpp"

using namespace std;

class TokenStream {
private:
    bool full;
    stringstream exprStream;
    Token buffer;
public:
    TokenStream(): full(false), buffer(Token()) {};
    ~TokenStream() = default;
    /**
     * TokenStream class implementation.
     * This class is responsible for reading tokens from the input stream and managing a buffer for tokens.
     * It can pop a token from the input or push a token back into the buffer.
     * TODO: Handle errors and unexpected input more gracefully.
     * TODO: Consider using a more robust input method for token parsing, such as regex or a lexer.
     * TODO: Add support for more token types and operators as needed.
     * TODO: Split token reading logic from token parsing logic for better separation of concerns.
     */
    Token pop();
    /**
     * Pushes a token back into the buffer.
     * If the buffer is already full, it will not push the token and will print an error message.
     * @param token The token to push back into the buffer.
     * @throws std::runtime_error If the buffer is full and cannot accept new tokens.
     */
    void push(Token token);
    /**
     * Peeks at the next token in the stream without removing it.
     * @return The next token in the stream.
     */
    Token peek();
    /**
     * Clears the token stream and resets the buffer.
     * This method clears the internal stringstream and resets the buffer state.
     */
    void clear();
    /**
     * Overloaded operator to insert a value into the token stream.
     * This allows for easy insertion of various types into the token stream.
     * @param value The value to insert into the token stream.
     * @return Reference to the current TokenStream instance.
     */
    template <typename T>
    TokenStream& operator<<(const T& value) {
        exprStream << value;
        return *this;
    }
};

#endif /* !CLISTREAM_H! */
