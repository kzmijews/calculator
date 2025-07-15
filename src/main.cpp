/**
 * Copyright © 2025 Karol Zmijewski

 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the “Software”), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,

 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

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
#include "spdlog/cfg/env.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "cxxopts.hpp"

namespace {
    /**
     * Interactive mode for the calculator.
     * This function allows users to enter expressions and get results in a console.
     * It handles various exceptions and provides feedback on errors.
     * @return 0 on success, non-zero on error.
     */
    int interactiveMode() {
        kz::calc::core::Calculator calculator;
        double value = 0.0;
        std::cout << "Enter expression (or q to quit): " << std::endl;
        std::cout << "> ";
        while (true) {
            try {
                std::string input = "";
                getline(std::cin, input);
                calculator << input;
                value = calculator.expression();
                std::cout << "= " << value << std::endl;
                std::cout << "> ";
            } catch(const kz::calc::core::EndOfExpression& e) {
                continue;
            } catch(const kz::calc::core::InvalidExpression& e) {
                std::cerr << "Invalid expression: " << e.what() << std::endl;
                calculator.reset();
                continue;
            } catch(const kz::calc::core::EndOfExecution& e) {
                std::cout << "Exiting calculator." << std::endl;
                break;
            } catch(const std::runtime_error& e) {
                std::cerr << "Runtime error: " << e.what() << std::endl;
                calculator.reset();
                continue;
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << std::endl;
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
    int executeMode(std::string expression) {
        kz::calc::core::Calculator calculator;
        try {
            calculator << expression;
            double result = calculator.expression();
            std::cout << "Result: " << result << std::endl;
        } catch (const kz::calc::core::InvalidExpression& e) {
            std::cerr << "Invalid expression: " << e.what() << std::endl;
            return 1;
        } catch (const kz::calc::core::EndOfExecution& e) {
            std::cout << "Exiting calculator." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
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
        kz::calc::core::Calculator calculator;
        kz::calc::ui::CalculatorUi calculator_ui(calculator);
        calculator_ui.setup();
        calculator_ui.getMainWindow()->show();
        return app.exec();
    }

    void configure_logger() {
        // Console logger setup
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        const char* cll_env = std::getenv("CONSOLE_LOG_LEVEL");
        spdlog::level::level_enum cll = (cll_env) ? spdlog::level::from_str(cll_env) : spdlog::level::warn;
        console_sink->set_level(cll);
        auto console_logger = std::make_shared<spdlog::logger>("console", console_sink);
        console_logger->set_pattern("[%T] [%^%l%$] %v");
        spdlog::register_logger(console_logger);
        // File logger setup
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("./logs/calc.txt", true);
        const char* fll_env = std::getenv("FILE_LOG_LEVEL");
        spdlog::level::level_enum fll = (fll_env) ? spdlog::level::from_str(fll_env) : spdlog::level::info;
        file_sink->set_level(fll);
        auto file_logger = std::make_shared<spdlog::logger>("file", file_sink);
        file_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
        spdlog::register_logger(file_logger);
        // Set the default logger to the console logger
        auto logger = std::make_shared<spdlog::logger>("main", spdlog::sinks_init_list{console_sink, file_sink});
        logger->set_level(spdlog::level::trace);
        logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
        spdlog::set_default_logger(logger);
        spdlog::cfg::load_env_levels("CALCULATOR_LOG_LEVEL");
    }
}

int main(int argc, char* argv[]) {
    configure_logger();
    spdlog::info("Calculator application started. Version: {}", APP_VERSION_STRING);
    cxxopts::Options options("Calculator", "A simple calculator application");
    options.add_options()
        ("h,help", "Show help")
        ("v,version", "Show version")
        ("u,user-interface", "Launch the calculator with a user interface (GUI)")
        ("i,interactive", "Launch in interactive (console) mode");
    options.add_options("Expression")
        ("e,expression", "Expression to evaluate", cxxopts::value<std::string>());
    auto args = options.parse(argc, argv);
    if (args.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }
    if (args.count("version")) {
        std::cout << "Calculator version: " << APP_VERSION_STRING << std::endl;
        return 0;
    }
    if (args.count("interactive")) {
        std::cout << "Launching calculator in interactive mode." << std::endl;
        return interactiveMode();
    } else if (args.count("expression")) {
        std::string expression = args["expression"].as<std::string>();
        return executeMode(expression);
    } else if (args.count("user-interface")) {
        std::cout << "Launching calculator with user interface (GUI)." << std::endl;
        return uiMode(argc, argv);
    }
    std::cout << "No expression provided. Use -h or --help for usage information." << std::endl;
    return 1;
}
