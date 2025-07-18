/**
 * Copyright © 2025 Karol Zmijewski

 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the “Software”), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,

 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef TSTREAM_H
#define TSTREAM_H

// standard library headers
#include <sstream>
// app headers
#include "tstream.hpp"
#include "token.hpp"

namespace kz::calc::core {
    class TokenStream {
    private:
        bool full;
        std::stringstream expr_stream;
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
            expr_stream << value;
            return *this;
        }
    };
}

#endif /* !TSTREAM_H! */
