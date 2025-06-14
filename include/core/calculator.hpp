#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "token.hpp"
#include "itstream.hpp"

class Calculator {
    private:
        ITokenStream& ts;
    public:
        Calculator(ITokenStream& inputStream) : ts(inputStream) {};
        ~Calculator() = default;
        double expression();
        double term();
        double primary();
};


#endif /* !CALCULATOR_H! */
