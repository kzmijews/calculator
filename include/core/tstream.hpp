#ifndef CLISTREAM_H
#define CLISTREAM_H

#include <sstream>
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
    Token pop();
    void push(Token token);
    Token peek();
    void clear();
    template <typename T>
    TokenStream& operator<<(const T& value) {
        exprStream << value;
        return *this;
    }
};

#endif /* !CLISTREAM_H! */