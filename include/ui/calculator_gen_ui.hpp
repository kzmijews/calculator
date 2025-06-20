/********************************************************************************
** Form generated from reading UI file 'calculatorRzdWrl.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CALCULATORRZDWRL_H
#define CALCULATORRZDWRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *resultBrowser;
    QGridLayout *keyboardLayout;
    QPushButton *zeroButton;
    QPushButton *eightButton;
    QPushButton *threeButton;
    QPushButton *sixButton;
    QPushButton *acButton;
    QPushButton *factorialButton;
    QPushButton *powerButton;
    QPushButton *piButton;
    QPushButton *rightParenButton;
    QPushButton *divButton;
    QPushButton *fourButton;
    QPushButton *sqrtButton;
    QPushButton *sevenButton;
    QPushButton *mulButton;
    QPushButton *oneButton;
    QPushButton *minusButton;
    QPushButton *sepButton;
    QPushButton *fiveButton;
    QPushButton *nineButton;
    QPushButton *rmButton;
    QPushButton *addButton;
    QPushButton *eqButton;
    QPushButton *leftParenButton;
    QPushButton *twoButton;

    void setupUi(QMainWindow *CalculatorMainWindow)
    {
        if (CalculatorMainWindow->objectName().isEmpty())
            CalculatorMainWindow->setObjectName("CalculatorMainWindow");
        CalculatorMainWindow->resize(600, 800);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalculatorMainWindow->sizePolicy().hasHeightForWidth());
        CalculatorMainWindow->setSizePolicy(sizePolicy);
        CalculatorMainWindow->setMinimumSize(QSize(300, 400));
        QFont font;
        font.setPointSize(18);
        CalculatorMainWindow->setFont(font);
        centralwidget = new QWidget(CalculatorMainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 0);
        resultBrowser = new QTextBrowser(centralwidget);
        resultBrowser->setObjectName("resultBrowser");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resultBrowser->sizePolicy().hasHeightForWidth());
        resultBrowser->setSizePolicy(sizePolicy1);
        resultBrowser->setMinimumSize(QSize(120, 30));
        resultBrowser->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(24);
        font1.setStyleStrategy(QFont::PreferAntialias);
        resultBrowser->setFont(font1);
        resultBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(29, 255, 0);"));
        resultBrowser->setLineWidth(1);
        resultBrowser->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        resultBrowser->setLineWrapColumnOrWidth(0);

        verticalLayout->addWidget(resultBrowser);

        keyboardLayout = new QGridLayout();
        keyboardLayout->setSpacing(20);
        keyboardLayout->setObjectName("keyboardLayout");
        keyboardLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        keyboardLayout->setContentsMargins(0, 20, 0, 20);
        zeroButton = new QPushButton(centralwidget);
        zeroButton->setObjectName("zeroButton");
        sizePolicy1.setHeightForWidth(zeroButton->sizePolicy().hasHeightForWidth());
        zeroButton->setSizePolicy(sizePolicy1);
        zeroButton->setMinimumSize(QSize(30, 30));
        zeroButton->setFont(font);
        zeroButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(zeroButton, 5, 0, 1, 1);

        eightButton = new QPushButton(centralwidget);
        eightButton->setObjectName("eightButton");
        sizePolicy1.setHeightForWidth(eightButton->sizePolicy().hasHeightForWidth());
        eightButton->setSizePolicy(sizePolicy1);
        eightButton->setMinimumSize(QSize(30, 30));
        eightButton->setFont(font);
        eightButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(eightButton, 2, 1, 1, 1);

        threeButton = new QPushButton(centralwidget);
        threeButton->setObjectName("threeButton");
        sizePolicy1.setHeightForWidth(threeButton->sizePolicy().hasHeightForWidth());
        threeButton->setSizePolicy(sizePolicy1);
        threeButton->setMinimumSize(QSize(30, 30));
        threeButton->setFont(font);
        threeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(threeButton, 4, 2, 1, 1);

        sixButton = new QPushButton(centralwidget);
        sixButton->setObjectName("sixButton");
        sizePolicy1.setHeightForWidth(sixButton->sizePolicy().hasHeightForWidth());
        sixButton->setSizePolicy(sizePolicy1);
        sixButton->setMinimumSize(QSize(30, 30));
        sixButton->setFont(font);
        sixButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(sixButton, 3, 2, 1, 1);

        acButton = new QPushButton(centralwidget);
        acButton->setObjectName("acButton");
        sizePolicy1.setHeightForWidth(acButton->sizePolicy().hasHeightForWidth());
        acButton->setSizePolicy(sizePolicy1);
        acButton->setMinimumSize(QSize(30, 30));
        acButton->setFont(font);
        acButton->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 27, 36);"));

        keyboardLayout->addWidget(acButton, 1, 0, 1, 1);

        factorialButton = new QPushButton(centralwidget);
        factorialButton->setObjectName("factorialButton");
        sizePolicy1.setHeightForWidth(factorialButton->sizePolicy().hasHeightForWidth());
        factorialButton->setSizePolicy(sizePolicy1);
        factorialButton->setMinimumSize(QSize(30, 30));
        factorialButton->setFont(font);
        factorialButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(factorialButton, 0, 3, 1, 1);

        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName("powerButton");
        sizePolicy1.setHeightForWidth(powerButton->sizePolicy().hasHeightForWidth());
        powerButton->setSizePolicy(sizePolicy1);
        powerButton->setMinimumSize(QSize(30, 30));
        powerButton->setFont(font);
        powerButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(powerButton, 0, 2, 1, 1);

        piButton = new QPushButton(centralwidget);
        piButton->setObjectName("piButton");
        sizePolicy1.setHeightForWidth(piButton->sizePolicy().hasHeightForWidth());
        piButton->setSizePolicy(sizePolicy1);
        piButton->setMinimumSize(QSize(30, 30));
        piButton->setFont(font);
        piButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(piButton, 0, 1, 1, 1);

        rightParenButton = new QPushButton(centralwidget);
        rightParenButton->setObjectName("rightParenButton");
        sizePolicy1.setHeightForWidth(rightParenButton->sizePolicy().hasHeightForWidth());
        rightParenButton->setSizePolicy(sizePolicy1);
        rightParenButton->setMinimumSize(QSize(30, 30));
        rightParenButton->setFont(font);
        rightParenButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(rightParenButton, 1, 2, 1, 1);

        divButton = new QPushButton(centralwidget);
        divButton->setObjectName("divButton");
        sizePolicy1.setHeightForWidth(divButton->sizePolicy().hasHeightForWidth());
        divButton->setSizePolicy(sizePolicy1);
        divButton->setMinimumSize(QSize(30, 30));
        divButton->setFont(font);
        divButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(divButton, 1, 3, 1, 1);

        fourButton = new QPushButton(centralwidget);
        fourButton->setObjectName("fourButton");
        sizePolicy1.setHeightForWidth(fourButton->sizePolicy().hasHeightForWidth());
        fourButton->setSizePolicy(sizePolicy1);
        fourButton->setMinimumSize(QSize(30, 30));
        fourButton->setFont(font);
        fourButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(fourButton, 3, 0, 1, 1);

        sqrtButton = new QPushButton(centralwidget);
        sqrtButton->setObjectName("sqrtButton");
        sizePolicy1.setHeightForWidth(sqrtButton->sizePolicy().hasHeightForWidth());
        sqrtButton->setSizePolicy(sizePolicy1);
        sqrtButton->setMinimumSize(QSize(30, 30));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setStrikeOut(false);
        sqrtButton->setFont(font2);
        sqrtButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(sqrtButton, 0, 0, 1, 1);

        sevenButton = new QPushButton(centralwidget);
        sevenButton->setObjectName("sevenButton");
        sizePolicy1.setHeightForWidth(sevenButton->sizePolicy().hasHeightForWidth());
        sevenButton->setSizePolicy(sizePolicy1);
        sevenButton->setMinimumSize(QSize(30, 30));
        sevenButton->setFont(font);
        sevenButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(sevenButton, 2, 0, 1, 1);

        mulButton = new QPushButton(centralwidget);
        mulButton->setObjectName("mulButton");
        sizePolicy1.setHeightForWidth(mulButton->sizePolicy().hasHeightForWidth());
        mulButton->setSizePolicy(sizePolicy1);
        mulButton->setMinimumSize(QSize(30, 30));
        mulButton->setFont(font);
        mulButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(mulButton, 2, 3, 1, 1);

        oneButton = new QPushButton(centralwidget);
        oneButton->setObjectName("oneButton");
        sizePolicy1.setHeightForWidth(oneButton->sizePolicy().hasHeightForWidth());
        oneButton->setSizePolicy(sizePolicy1);
        oneButton->setMinimumSize(QSize(30, 30));
        oneButton->setFont(font);
        oneButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(oneButton, 4, 0, 1, 1);

        minusButton = new QPushButton(centralwidget);
        minusButton->setObjectName("minusButton");
        sizePolicy1.setHeightForWidth(minusButton->sizePolicy().hasHeightForWidth());
        minusButton->setSizePolicy(sizePolicy1);
        minusButton->setMinimumSize(QSize(30, 30));
        minusButton->setFont(font);
        minusButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(minusButton, 3, 3, 1, 1);

        sepButton = new QPushButton(centralwidget);
        sepButton->setObjectName("sepButton");
        sizePolicy1.setHeightForWidth(sepButton->sizePolicy().hasHeightForWidth());
        sepButton->setSizePolicy(sizePolicy1);
        sepButton->setMinimumSize(QSize(30, 30));
        sepButton->setFont(font);
        sepButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(sepButton, 5, 1, 1, 1);

        fiveButton = new QPushButton(centralwidget);
        fiveButton->setObjectName("fiveButton");
        sizePolicy1.setHeightForWidth(fiveButton->sizePolicy().hasHeightForWidth());
        fiveButton->setSizePolicy(sizePolicy1);
        fiveButton->setMinimumSize(QSize(30, 30));
        fiveButton->setFont(font);
        fiveButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(fiveButton, 3, 1, 1, 1);

        nineButton = new QPushButton(centralwidget);
        nineButton->setObjectName("nineButton");
        sizePolicy1.setHeightForWidth(nineButton->sizePolicy().hasHeightForWidth());
        nineButton->setSizePolicy(sizePolicy1);
        nineButton->setMinimumSize(QSize(30, 30));
        nineButton->setFont(font);
        nineButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(nineButton, 2, 2, 1, 1);

        rmButton = new QPushButton(centralwidget);
        rmButton->setObjectName("rmButton");
        sizePolicy1.setHeightForWidth(rmButton->sizePolicy().hasHeightForWidth());
        rmButton->setSizePolicy(sizePolicy1);
        rmButton->setMinimumSize(QSize(30, 30));
        rmButton->setFont(font);
        rmButton->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 27, 36);"));

        keyboardLayout->addWidget(rmButton, 5, 2, 1, 1);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(30, 30));
        addButton->setFont(font);
        addButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 95, 180);"));

        keyboardLayout->addWidget(addButton, 4, 3, 1, 1);

        eqButton = new QPushButton(centralwidget);
        eqButton->setObjectName("eqButton");
        sizePolicy1.setHeightForWidth(eqButton->sizePolicy().hasHeightForWidth());
        eqButton->setSizePolicy(sizePolicy1);
        eqButton->setMinimumSize(QSize(30, 30));
        eqButton->setFont(font);
        eqButton->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 162, 105);"));

        keyboardLayout->addWidget(eqButton, 5, 3, 1, 1);

        leftParenButton = new QPushButton(centralwidget);
        leftParenButton->setObjectName("leftParenButton");
        sizePolicy1.setHeightForWidth(leftParenButton->sizePolicy().hasHeightForWidth());
        leftParenButton->setSizePolicy(sizePolicy1);
        leftParenButton->setMinimumSize(QSize(30, 30));
        leftParenButton->setFont(font);
        leftParenButton->setStyleSheet(QString::fromUtf8("background-color:rgb(26, 95, 180);"));

        keyboardLayout->addWidget(leftParenButton, 1, 1, 1, 1);

        twoButton = new QPushButton(centralwidget);
        twoButton->setObjectName("twoButton");
        sizePolicy1.setHeightForWidth(twoButton->sizePolicy().hasHeightForWidth());
        twoButton->setSizePolicy(sizePolicy1);
        twoButton->setMinimumSize(QSize(30, 30));
        twoButton->setFont(font);
        twoButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));

        keyboardLayout->addWidget(twoButton, 4, 1, 1, 1);


        verticalLayout->addLayout(keyboardLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);
        CalculatorMainWindow->setCentralWidget(centralwidget);

        retranslateUi(CalculatorMainWindow);

        QMetaObject::connectSlotsByName(CalculatorMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalculatorMainWindow)
    {
        CalculatorMainWindow->setWindowTitle(QCoreApplication::translate("CalculatorMainWindow", "Calculator", nullptr));
        zeroButton->setText(QCoreApplication::translate("CalculatorMainWindow", "0", nullptr));
#if QT_CONFIG(shortcut)
        zeroButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        eightButton->setText(QCoreApplication::translate("CalculatorMainWindow", "8", nullptr));
#if QT_CONFIG(shortcut)
        eightButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        threeButton->setText(QCoreApplication::translate("CalculatorMainWindow", "3", nullptr));
#if QT_CONFIG(shortcut)
        threeButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        sixButton->setText(QCoreApplication::translate("CalculatorMainWindow", "6", nullptr));
#if QT_CONFIG(shortcut)
        sixButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        acButton->setText(QCoreApplication::translate("CalculatorMainWindow", "AC", nullptr));
        factorialButton->setText(QCoreApplication::translate("CalculatorMainWindow", "!", nullptr));
#if QT_CONFIG(shortcut)
        factorialButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "!", nullptr));
#endif // QT_CONFIG(shortcut)
        powerButton->setText(QCoreApplication::translate("CalculatorMainWindow", "^", nullptr));
#if QT_CONFIG(shortcut)
        powerButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "^", nullptr));
#endif // QT_CONFIG(shortcut)
        piButton->setText(QCoreApplication::translate("CalculatorMainWindow", "pi", nullptr));
#if QT_CONFIG(shortcut)
        piButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "P", nullptr));
#endif // QT_CONFIG(shortcut)
        rightParenButton->setText(QCoreApplication::translate("CalculatorMainWindow", ")", nullptr));
#if QT_CONFIG(shortcut)
        rightParenButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", ")", nullptr));
#endif // QT_CONFIG(shortcut)
        divButton->setText(QCoreApplication::translate("CalculatorMainWindow", "/", nullptr));
#if QT_CONFIG(shortcut)
        divButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "/", nullptr));
#endif // QT_CONFIG(shortcut)
        fourButton->setText(QCoreApplication::translate("CalculatorMainWindow", "4", nullptr));
#if QT_CONFIG(shortcut)
        fourButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        sqrtButton->setText(QCoreApplication::translate("CalculatorMainWindow", "sqrt", nullptr));
#if QT_CONFIG(shortcut)
        sqrtButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "S", nullptr));
#endif // QT_CONFIG(shortcut)
        sevenButton->setText(QCoreApplication::translate("CalculatorMainWindow", "7", nullptr));
#if QT_CONFIG(shortcut)
        sevenButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        mulButton->setText(QCoreApplication::translate("CalculatorMainWindow", "x", nullptr));
#if QT_CONFIG(shortcut)
        mulButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        oneButton->setText(QCoreApplication::translate("CalculatorMainWindow", "1", nullptr));
#if QT_CONFIG(shortcut)
        oneButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        minusButton->setText(QCoreApplication::translate("CalculatorMainWindow", "-", nullptr));
#if QT_CONFIG(shortcut)
        minusButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "-", nullptr));
#endif // QT_CONFIG(shortcut)
        sepButton->setText(QCoreApplication::translate("CalculatorMainWindow", ".", nullptr));
#if QT_CONFIG(shortcut)
        sepButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", ",", nullptr));
#endif // QT_CONFIG(shortcut)
        fiveButton->setText(QCoreApplication::translate("CalculatorMainWindow", "5", nullptr));
#if QT_CONFIG(shortcut)
        fiveButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        nineButton->setText(QCoreApplication::translate("CalculatorMainWindow", "9", nullptr));
#if QT_CONFIG(shortcut)
        nineButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        rmButton->setText(QCoreApplication::translate("CalculatorMainWindow", "<<", nullptr));
#if QT_CONFIG(shortcut)
        rmButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        addButton->setText(QCoreApplication::translate("CalculatorMainWindow", "+", nullptr));
#if QT_CONFIG(shortcut)
        addButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        eqButton->setText(QCoreApplication::translate("CalculatorMainWindow", "=", nullptr));
#if QT_CONFIG(shortcut)
        eqButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        leftParenButton->setText(QCoreApplication::translate("CalculatorMainWindow", "(", nullptr));
#if QT_CONFIG(shortcut)
        leftParenButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "(", nullptr));
#endif // QT_CONFIG(shortcut)
        twoButton->setText(QCoreApplication::translate("CalculatorMainWindow", "2", nullptr));
#if QT_CONFIG(shortcut)
        twoButton->setShortcut(QCoreApplication::translate("CalculatorMainWindow", "2", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class CalculatorMainWindow: public Ui_CalculatorMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CALCULATORRZDWRL_H
