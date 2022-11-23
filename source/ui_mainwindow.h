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
    QPushButton *stop;
    QPushButton *IP_restruct;
    QPushButton *TCP_restrcut;
    QPushButton *pushButton_2;
    QPushButton *Exit;
    QWidget *layoutWidget2;
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
        stopped->setGeometry(QRect(50, 140, 171, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        stopped->setFont(font);
        stopped->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 490, 171, 41));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 0, 701, 41));
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
        Interface->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));

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
        stop = new QPushButton(centralWidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(860, 290, 121, 61));
        stop->setFont(font2);
        stop->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        IP_restruct = new QPushButton(centralWidget);
        IP_restruct->setObjectName(QString::fromUtf8("IP_restruct"));
        IP_restruct->setGeometry(QRect(860, 410, 121, 61));
        IP_restruct->setFont(font2);
        IP_restruct->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        TCP_restrcut = new QPushButton(centralWidget);
        TCP_restrcut->setObjectName(QString::fromUtf8("TCP_restrcut"));
        TCP_restrcut->setGeometry(QRect(860, 530, 121, 61));
        TCP_restrcut->setFont(font2);
        TCP_restrcut->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(860, 90, 121, 31));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        Exit = new QPushButton(centralWidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(860, 650, 121, 61));
        Exit->setFont(font2);
        Exit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(154, 153, 150);"));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 90, 701, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget2);
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
        layoutWidget1->raise();
        layoutWidget1->raise();
        layoutWidget1->raise();
        stopped->raise();
        label->raise();
        packet_info->raise();
        textBrowser->raise();
        start->raise();
        stop->raise();
        IP_restruct->raise();
        TCP_restrcut->raise();
        pushButton_2->raise();
        pushButton->raise();
        Exit->raise();
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
        stopped->setText(QCoreApplication::translate("MainWindow", "Packet display list", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Packet details", nullptr));
        Inter_sel->setText(QCoreApplication::translate("MainWindow", "Select the network adapter to listen on", nullptr));
        input_rule->setText(QCoreApplication::translate("MainWindow", "Input the filtering rule     ", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        IP_restruct->setText(QCoreApplication::translate("MainWindow", "IP Restruct", nullptr));
        TCP_restrcut->setText(QCoreApplication::translate("MainWindow", "TCP Restruct", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Input the search criteria  ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
