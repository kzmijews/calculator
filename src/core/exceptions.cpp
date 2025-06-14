#include "exceptions.hpp"

using namespace std;

InvalidExpression::InvalidExpression(const string& msg) : message(msg) { }

const char* InvalidExpression::what() const noexcept {
    return message.c_str();
}