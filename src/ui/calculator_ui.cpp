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
    void CalculatorUi::keyboardButtonClicked(QTextBrowser* resultBrowser, const QString& text) {
        if (text == "AC") {
            resultBrowser->setText("");
            calculator.reset();
        } else if (text == "=") {
            std::string expression = resultBrowser->toPlainText().toStdString();
            calculator << expression << ";";
            try {
                double result = calculator.expression();
                resultBrowser->setText("");
                resultBrowser->insertPlainText(QString::number(result));
                spdlog::info("[umode] Result: {} = {}", expression, result);
            } catch (const kz::calc::core::InvalidExpression& e) {
                resultBrowser->setText("ERR: invalid/unsupported");
                spdlog::error("[umode] Invalid expression encountered: {}", e.what());
                calculator.reset();
            } catch (const std::runtime_error& e) {
                resultBrowser->setText("ERR: unexpected error");
                spdlog::error("[umode] Runtime error: {}", e.what());
                calculator.reset();
            }
        } else if (text == "x") {
            resultBrowser->insertPlainText("*");
        } else if (text == "pi") {
            resultBrowser->insertPlainText(QString::number(M_PI));
        } else if (text == "sqrt") {
            resultBrowser->insertPlainText("sqrt(");
        } else if (text == "<<") {
            QString currentText = resultBrowser->toPlainText();
            if (!currentText.isEmpty()) {
                // Remove the last character
                currentText.chop(1);
                resultBrowser->setText("");
                resultBrowser->insertPlainText(currentText);
            }
        } else if (text == "sep") {
            resultBrowser->insertPlainText(".");
        } else {
            // Prevent starting with an operator
            if (resultBrowser->toPlainText().isEmpty() && (text == "+" || text == "x" || text == "/" || text == "^")) {
                return;
            }
            resultBrowser->insertPlainText(text);
        }
    }

    void CalculatorUi::connectButtons() {
        QObject::connect(zeroButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, zeroButton->text()); });
        QObject::connect(oneButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, oneButton->text()); });
        QObject::connect(twoButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, twoButton->text()); });
        QObject::connect(threeButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, threeButton->text()); });
        QObject::connect(fourButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, fourButton->text()); });
        QObject::connect(fiveButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, fiveButton->text()); });
        QObject::connect(sixButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, sixButton->text()); });
        QObject::connect(sevenButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, sevenButton->text()); });
        QObject::connect(eightButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, eightButton->text()); });
        QObject::connect(nineButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, nineButton->text()); });
        QObject::connect(eqButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, eqButton->text()); });
        QObject::connect(addButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, addButton->text()); });
        QObject::connect(minusButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, minusButton->text()); });
        QObject::connect(divButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, divButton->text()); });
        QObject::connect(mulButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, mulButton->text()); });
        QObject::connect(sepButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, sepButton->text()); });
        QObject::connect(acButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, acButton->text()); });
        QObject::connect(rmButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, rmButton->text()); });
        QObject::connect(leftParenButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, leftParenButton->text()); });
        QObject::connect(rightParenButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, rightParenButton->text()); });
        QObject::connect(powerButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, powerButton->text()); });
        QObject::connect(piButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, piButton->text()); });
        QObject::connect(factorialButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, factorialButton->text()); });
        QObject::connect(sqrtButton, &QPushButton::clicked, [&]() { keyboardButtonClicked(resultBrowser, sqrtButton->text()); });
    }

    CalculatorUi::CalculatorUi(kz::calc::core::Calculator& calculator) : calculator(calculator) {
        mainWindow = std::make_unique<QMainWindow>();
    }

    QMainWindow* CalculatorUi::getMainWindow() const {
        return mainWindow.get();
    }

    void CalculatorUi::setup() {
        setupUi(mainWindow.get());
        connectButtons();
    }
}
