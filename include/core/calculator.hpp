#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "token.hpp"
#include "tstream.hpp"

class Calculator {
private:
    TokenStream ts;
public:
    Calculator() {};
    ~Calculator() = default;
    double expression();
    double term();
    double primary();
    Calculator& operator<<(const std::string& expr) {
        ts << expr;
        return *this;
    };
    void reset() {
        ts.clear();
    };
};


#endif /* !CALCULATOR_H! */
