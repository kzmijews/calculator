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
#include "exceptions.hpp"
#include "calculator.hpp"
#include "calculator_ui.hpp"
// external library headers
#include "spdlog/spdlog.h"

namespace kz::calc::ui {
    void CalculatorUi::keyboard_button_clicked(QTextBrowser* result_browser, const QString& text) {
        if (text == "AC") {
            result_browser->setText("");
            calculator.reset();
        } else if (text == "=") {
            std::string expression = result_browser->toPlainText().toStdString();
            calculator << expression << ";";
            try {
                double result = calculator.expression();
                result_browser->setText("");
                result_browser->insertPlainText(QString::number(result));
                spdlog::info("[umode] Result: {} = {}", expression, result);
            } catch (const kz::calc::core::InvalidExpression& e) {
                result_browser->setText("ERR: invalid/unsupported");
                spdlog::error("[umode] Invalid expression encountered: {}", e.what());
                calculator.reset();
            } catch (const std::runtime_error& e) {
                result_browser->setText("ERR: unexpected error");
                spdlog::error("[umode] Runtime error: {}", e.what());
                calculator.reset();
            }
        } else if (text == "x") {
            result_browser->insertPlainText("*");
        } else if (text == "pi") {
            result_browser->insertPlainText(QString::number(M_PI));
        } else if (text == "sqrt") {
            result_browser->insertPlainText("sqrt(");
        } else if (text == "<<") {
            QString current_text = result_browser->toPlainText();
            if (!current_text.isEmpty()) {
                // Remove the last character
                current_text.chop(1);
                result_browser->setText("");
                result_browser->insertPlainText(current_text);
            }
        } else if (text == "sep") {
            result_browser->insertPlainText(".");
        } else {
            // Prevent starting with an operator
            if (result_browser->toPlainText().isEmpty() && (text == "+" || text == "x" || text == "/" || text == "^")) {
                return;
            }
            result_browser->insertPlainText(text);
        }
    }

    void CalculatorUi::connect_buttons() {
        QObject::connect(zeroButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, zeroButton->text()); });
        QObject::connect(oneButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, oneButton->text()); });
        QObject::connect(twoButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, twoButton->text()); });
        QObject::connect(threeButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, threeButton->text()); });
        QObject::connect(fourButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, fourButton->text()); });
        QObject::connect(fiveButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, fiveButton->text()); });
        QObject::connect(sixButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, sixButton->text()); });
        QObject::connect(sevenButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, sevenButton->text()); });
        QObject::connect(eightButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, eightButton->text()); });
        QObject::connect(nineButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, nineButton->text()); });
        QObject::connect(eqButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, eqButton->text()); });
        QObject::connect(addButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, addButton->text()); });
        QObject::connect(minusButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, minusButton->text()); });
        QObject::connect(divButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, divButton->text()); });
        QObject::connect(mulButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, mulButton->text()); });
        QObject::connect(sepButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, sepButton->text()); });
        QObject::connect(acButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, acButton->text()); });
        QObject::connect(rmButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, rmButton->text()); });
        QObject::connect(leftParenButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, leftParenButton->text()); });
        QObject::connect(rightParenButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, rightParenButton->text()); });
        QObject::connect(powerButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, powerButton->text()); });
        QObject::connect(piButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, piButton->text()); });
        QObject::connect(factorialButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, factorialButton->text()); });
        QObject::connect(sqrtButton, &QPushButton::clicked, [&]() { keyboard_button_clicked(resultBrowser, sqrtButton->text()); });
    }

    CalculatorUi::CalculatorUi(kz::calc::core::Calculator& calculator) : calculator(calculator) {
        main_window = std::make_unique<QMainWindow>();
    }

    QMainWindow* CalculatorUi::get_main_window() const {
        return main_window.get();
    }

    void CalculatorUi::setup() {
        setupUi(main_window.get());
        connect_buttons();
    }
}
