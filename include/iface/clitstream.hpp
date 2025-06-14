#ifndef CLISTREAM_H
#define CLISTREAM_H

#include "itstream.hpp"
#include "token.hpp"

class CLITokenStream : public ITokenStream {
private:
    bool full;
    Token buffer;
public:
    CLITokenStream(): full(false), buffer(Token()) {};
    Token pop();
    void push(Token token);
    Token peek() const;
    void clean();
};

#endif /* !CLISTREAM_H! */