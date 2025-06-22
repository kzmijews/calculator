#ifndef CALCULATOR_UI_H
#define CALCULATOR_UI_H

#include <memory>
#include "calculator.hpp"
#include "calculator_gen_ui.hpp"

namespace Ui {
    class CalculatorUi: protected CalculatorMainWindow {
    private:
        Calculator &calculator;
        std::unique_ptr<QMainWindow> mainWindow;
        void connectButtons();
        void keyboardButtonClicked(QTextBrowser* resultBrowser, const QString& text);
    public:
        CalculatorUi(Calculator &calculator);
        ~CalculatorUi() = default;
        void setup();
        QMainWindow* getMainWindow() const;
    };
} // namespace Ui

#endif /* !CALCULATOR_UI_H! */
