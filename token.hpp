class Token {
private:
    char kind;
    double value;
public:
    Token(char kind = 0, double value = 0.0): kind(kind), value(value) {}
    char getKind() const { return kind; }
    double getValue() const { return value; }
    bool isNumber() const { return kind == '8'; } // Assuming '8' is the kind for numbers
    bool isOperator() const { return kind == '+' || kind == '-' || kind == '*' || kind == '/'; }
    bool isParenthesis() const { return kind == '(' || kind == ')'; }
    bool isEnd() const { return kind == 0; } // Assuming 0 is used to indicate the end of input
    operator double() const { return value; } // Allows implicit conversion to double
};

class TokenStream {
private:
    bool full;
    Token buffer;
public:
    TokenStream(): full(false), buffer(Token()) {};
    Token pop();
    void push(Token token);
};