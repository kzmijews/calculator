#include "calculator_ui.hpp"

Ui::CalculatorUi::CalculatorUi() {
    mainWindow = std::make_unique<QMainWindow>();
}

QMainWindow* Ui::CalculatorUi::getMainWindow() const {
    return mainWindow.get();
}

void Ui::CalculatorUi::keyboardButtonClicked(QTextBrowser* resultBrowser, const QString& text) {
    if (text == "AC") {
        resultBrowser->setText("");
    } else if (text == "=") {
        // Evaluate the expression in the resultBrowser
        // This is a placeholder for actual evaluation logic
        resultBrowser->append("Evaluated expression");
    } else {
        resultBrowser->append(text);
    }
}

void Ui::CalculatorUi::setup() {
    setupUi(mainWindow.get());
}

void Ui::CalculatorUi::createItems() {
    //auto buttonAction = [&](const QString& buttonText) { keyboardButtonClicked(ui.resultBrowser, buttonText); };
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
