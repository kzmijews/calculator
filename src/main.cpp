#include <iostream>
#include "cxxopts.hpp"
#include "token.hpp"
#include "calculator.hpp"
#include "calculator_ui.hpp"
#include "exceptions.hpp"

using namespace std;

int interactiveMode() {
    Calculator calculator;
    double value = 0.0;
    cout << "Enter expression (or q to quit): " << endl;
    cout << "> ";
    while (true) {
        try {
            string input = "";
            getline(cin, input);
            calculator << input;
            value = calculator.expression();
            cout << "= " << value << endl;
            cout << "> ";
        } catch(const EndOfExpression& e) {
            continue;
        } catch(const InvalidExpression& e) {
            cerr << "Invalid expression: " << e.what() << endl;
            calculator.reset();
            continue;
        } catch(const EndOfExecution& e) {
            cout << "Exiting calculator." << endl;
            break;
        } catch(const runtime_error& e) {
            cerr << "Runtime error: " << e.what() << endl;
            calculator.reset();
            continue;
        } catch(const exception& e) {
            cerr << "An error occurred: " << e.what() << endl;
            calculator.reset();
            continue;
        }
    }
    return 0;
}

int executeMode(string expression) {
    Calculator calculator;
    try {
        calculator << expression;
        double result = calculator.expression();
        cout << "Result: " << result << endl;
    } catch (const InvalidExpression& e) {
        cerr << "Invalid expression: " << e.what() << endl;
        return 1;
    } catch (const EndOfExecution& e) {
        cout << "Exiting calculator." << endl;
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    }
    return 0;
}

int uiMode(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Calculator calculator;
    Ui::CalculatorUi calculatorUi(calculator);
    calculatorUi.setup();
    calculatorUi.getMainWindow()->show();
    return app.exec();
}

int main(int argc, char* argv[]) {
    cxxopts::Options options("Calculator", "A simple calculator application");
    options.add_options()
        ("h,help", "Show help")
        ("v,version", "Show version")
        ("u,user-interface", "Launch the calculator with a user interface (GUI)")
        ("i,interactive", "Launch in interactive (console) mode");
    options.add_options("Expression")
        ("e,expression", "Expression to evaluate", cxxopts::value<string>());
    auto args = options.parse(argc, argv);
    if (args.count("help")) {
        cout << options.help() << endl;
        return 0;
    }
    if (args.count("version")) {
        cout << "Calculator version: 1.0.0" << endl;
        return 0;
    }
    if (args.count("interactive")) {
        cout << "Launching calculator in interactive mode." << endl;
        return interactiveMode();
    } else if (args.count("expression")) {
        string expression = args["expression"].as<string>();
        return executeMode(expression);
    } else if (args.count("user-interface")) {
        cout << "Launching calculator with user interface (GUI)." << endl;
        return uiMode(argc, argv);
    }
    cout << "No expression provided. Use -h or --help for usage information." << endl;
    return 1;
}