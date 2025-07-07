// standard library headers
#include <iostream>
// app headers
#include "calculator.hpp"
#include "calculator_ui.hpp"
#include "exceptions.hpp"
#include "token.hpp"
// generated headers by CMake
#include "version.hpp"
// external library headers
#include "cxxopts.hpp"

using namespace std;

/**
 * Interactive mode for the calculator.
 * This function allows users to enter expressions and get results in a console.
 * It handles various exceptions and provides feedback on errors.
 * @return 0 on success, non-zero on error.
 */
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

/**
 * Executes a single expression in the calculator.
 * This function evaluates the provided expression and prints the result.
 * It handles exceptions related to invalid expressions and end of execution.
 * @param expression The expression to evaluate.
 * @return 0 on success, non-zero on error.
 */
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

/**
 * Launches the calculator with a user interface (GUI).
 * This function initializes the Qt application and sets up the main window for the calculator.
 * It uses the CalculatorUi class to manage the user interface.
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return The exit code of the application.
 *         Returns 0 on successful execution, or a non-zero value on error.
 */
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
        cout << "Calculator version: " << APP_VERSION_STRING << endl;
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
