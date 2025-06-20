#ifndef CALCULATOR_UI_H
#define CALCULATOR_UI_H

#include <memory>
#include "calculator_gen_ui.hpp"

namespace Ui {
    class CalculatorUi: protected CalculatorMainWindow {
    private:
        std::unique_ptr<QMainWindow> mainWindow;
        void keyboardButtonClicked(QTextBrowser* resultBrowser, const QString& text);
    public:
        CalculatorUi();
        ~CalculatorUi() = default;
        void setup();
        void createItems();
        QMainWindow* getMainWindow() const;
    };
} // namespace Ui

#endif /* !CALCULATOR_UI_H! */
