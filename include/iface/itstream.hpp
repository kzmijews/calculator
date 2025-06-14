#ifndef ITSTREAM_H
#define ITSTREAM_H

#include "token.hpp"

class ITokenStream {
public:
    virtual ~ITokenStream() = default; // Virtual destructor for safe polymorphic deletion
    virtual Token pop() = 0;
    virtual void push(Token token) = 0;
    virtual Token peek() const = 0;
    virtual void clean() = 0;
};

#endif /* !ITSTREAM_H! */