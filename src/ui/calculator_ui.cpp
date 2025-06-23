#include "calculator.hpp"
#include "calculator_ui.hpp"
#include <iostream>

void Ui::CalculatorUi::keyboardButtonClicked(QTextBrowser* resultBrowser, const QString& text) {
    if (text == "AC") {
        resultBrowser->setText("");
        calculator.reset();
    } else if (text == "=") {
        calculator << resultBrowser->toPlainText().toStdString() << ";";
        double result = calculator.expression();
        resultBrowser->setText("");
        resultBrowser->insertPlainText(QString::number(result));
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

void Ui::CalculatorUi::connectButtons() {
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

Ui::CalculatorUi::CalculatorUi(Calculator& calculator) : calculator(calculator) {
    mainWindow = std::make_unique<QMainWindow>();
}

QMainWindow* Ui::CalculatorUi::getMainWindow() const {
    return mainWindow.get();
}

void Ui::CalculatorUi::setup() {
    setupUi(mainWindow.get());
    connectButtons();
}