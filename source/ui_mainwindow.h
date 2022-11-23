/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *stopped;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Inter_sel;
    QComboBox *Interface;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *input_rule;
    QLineEdit *fliter_rule;
    QTableWidget *packet_info;
    QTextBrowser *textBrowser;
    QPushButton *start;
    QPushButton *start_2;
    QPushButton *start_3;
    QPushButton *start_4;
    QPushButton *pushButton_2;
    QPushButton *start_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1191, 846);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stopped = new QLabel(centralWidget);
        stopped->setObjectName(QString::fromUtf8("stopped"));
        stopped->setGeometry(QRect(50, 140, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("aakar"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        stopped->setFont(font);
        stopped->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 490, 111, 31));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 0, 701, 34));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Inter_sel = new QLabel(layoutWidget);
        Inter_sel->setObjectName(QString::fromUtf8("Inter_sel"));
        Inter_sel->setFont(font);
        Inter_sel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(Inter_sel);

        Interface = new QComboBox(layoutWidget);
        Interface->setObjectName(QString::fromUtf8("Interface"));
        Interface->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));

        horizontalLayout->addWidget(Interface);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 40, 701, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        input_rule = new QLabel(layoutWidget1);
        input_rule->setObjectName(QString::fromUtf8("input_rule"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        input_rule->setFont(font1);
        input_rule->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(input_rule);

        fliter_rule = new QLineEdit(layoutWidget1);
        fliter_rule->setObjectName(QString::fromUtf8("fliter_rule"));
        fliter_rule->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));

        horizontalLayout_3->addWidget(fliter_rule);

        packet_info = new QTableWidget(centralWidget);
        packet_info->setObjectName(QString::fromUtf8("packet_info"));
        packet_info->setGeometry(QRect(50, 180, 701, 301));
        packet_info->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 530, 701, 241));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(860, 180, 121, 61));
        QFont font2;
        font2.setPointSize(16);
        start->setFont(font2);
        start->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        start_2 = new QPushButton(centralWidget);
        start_2->setObjectName(QString::fromUtf8("start_2"));
        start_2->setGeometry(QRect(860, 290, 121, 61));
        start_2->setFont(font2);
        start_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        start_3 = new QPushButton(centralWidget);
        start_3->setObjectName(QString::fromUtf8("start_3"));
        start_3->setGeometry(QRect(860, 410, 121, 61));
        start_3->setFont(font2);
        start_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        start_4 = new QPushButton(centralWidget);
        start_4->setObjectName(QString::fromUtf8("start_4"));
        start_4->setGeometry(QRect(860, 530, 121, 61));
        start_4->setFont(font2);
        start_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(860, 90, 121, 31));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        start_5 = new QPushButton(centralWidget);
        start_5->setObjectName(QString::fromUtf8("start_5"));
        start_5->setGeometry(QRect(860, 650, 121, 61));
        start_5->setFont(font2);
        start_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 90, 701, 32));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(860, 50, 121, 31));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        stopped->raise();
        label->raise();
        packet_info->raise();
        textBrowser->raise();
        start->raise();
        start_2->raise();
        pushButton->raise();
        start_3->raise();
        start_4->raise();
        label_2->raise();
        lineEdit->raise();
        pushButton_2->raise();
        pushButton->raise();
        start_5->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1191, 28));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        stopped->setText(QCoreApplication::translate("MainWindow", "\346\212\223\345\214\205\345\267\262\345\201\234\346\255\242", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        Inter_sel->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\246\201\344\276\246\345\220\254\347\232\204\347\275\221\345\215\241", nullptr));
        input_rule->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\350\277\207\346\273\244\350\247\204\345\210\231", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\212\223\345\214\205", nullptr));
        start_2->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\346\212\223\345\214\205", nullptr));
        start_3->setText(QCoreApplication::translate("MainWindow", "IP\351\207\215\347\273\204", nullptr));
        start_4->setText(QCoreApplication::translate("MainWindow", "TCP\351\207\215\347\273\204", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\214\205\346\237\245\350\257\242", nullptr));
        start_5->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\346\237\245\350\257\242\346\235\241\344\273\266", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\214\205\350\277\207\346\273\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
