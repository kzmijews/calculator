#include <iostream>
#include "cxxopts.hpp"
#include "token.hpp"
#include "clitstream.hpp"
#include "calculator.hpp"
#include "exceptions.hpp"

using namespace std;


int interactiveMode() {
    CLITokenStream clits;
    Calculator calculator(clits);
    double value = 0.0;
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
            clits.push(Token()); // Push an empty token to clear the stream
            continue; // Continue to the next input
        }
        catch(const EndOfExecution& e) {
            cout << "Exiting calculator." << endl;
            break; // Exit the loop
        }
        catch(const std::runtime_error& e) {
            cerr << "Runtime error: " << e.what() << endl;
            clits.push(Token()); // Push an empty token to clear the stream
            continue; // Continue to the next input
        }
        catch(const std::exception& e) {
            cerr << "An error occurred: " << e.what() << endl;
            clits.push(Token()); // Push an empty token to clear the stream
            continue; // Continue to the next input
        }
    }
    return 0;
}


int main(int argc, char* argv[]) {
    // Set up command line options
    cxxopts::Options options("Calculator", "A simple calculator application");
    options.add_options()
        ("h,help", "Show help")
        ("v,version", "Show version")
        ("q,quit", "Quit the calculator")
        ("i,interactive", "Launch in interactive mode");
    options.add_options("Expression")
        ("e,expression", "Expression to evaluate", cxxopts::value<std::string>());
    auto args = options.parse(argc, argv);
    // -- Help
    if (args.count("help")) {
        cout << options.help() << std::endl;
        return 0;
    }
    // -- Version
    if (args.count("version")) {
        cout << "Calculator version: 1.0.0" << std::endl;
        return 0;
    }
    // -- Quit
    if (args.count("quit")) {
        cout << "Exiting calculator." << std::endl;
        return 0;
    }
    // -- Interactive mode
    if (args.count("interactive")) {
        cout << "Launching calculator in interactive mode." << std::endl;
        return interactiveMode();
    } else if (args.count("expression")) {
        // -- Expression mode
        // TODO: Implement expression evaluation
        std::string expression = args["expression"].as<std::string>();
        return 1;
    }
    cout << "No expression provided. Use -h or --help for usage information." << std::endl;
    return 1;
}