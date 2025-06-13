#include <iostream>
#include "token.hpp"
#include "calculator.hpp"
#include "exceptions.hpp"

using namespace std;

int main() {
    Calculator calculator;
    TokenStream ts;
    double value = 0.0;
    cout << "CALCULATOR" << endl;
    cout << "Enter expression (or q to quit): " << endl;
    cout << "> ";
    while (true) {
        try {
            value = calculator.expression();
            cout << "= " << value << endl;
            cout << "> ";
        }
        catch(const EndOfExpression& e) {
            continue; // End of expression, continue to the next input
        }
        catch(const InvalidExpression& e) {
            cerr << "Invalid expression: " << e.what() << endl;
            ts.push(Token()); // Push an empty token to clear the stream
            continue; // Continue to the next input
        }
        catch(const EndOfExecution& e) {
            cout << "Exiting calculator." << endl;
            break; // Exit the loop
        }
        catch(const std::runtime_error& e) {
            cerr << "Runtime error: " << e.what() << endl;
            ts.push(Token()); // Push an empty token to clear the stream
            continue; // Continue to the next input
        }
        catch(const std::exception& e) {
            cerr << "An error occurred: " << e.what() << endl;
            ts.push(Token()); // Push an empty token to clear the stream
            continue; // Continue to the next input
        }
    }
    return 0;
}