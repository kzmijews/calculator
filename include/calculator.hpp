#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "token.hpp"

class Calculator {
    private:
        TokenStream ts;
    public:
        Calculator();
        ~Calculator() = default;
        double expression();
        double term();
        double primary();
};


#endif /* !CALCULATOR_H! */
