/********************************************************************************
** Form generated from reading UI file 'js.ui'
**
** Created: Tue Jul 24 13:18:09 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JS_H
#define UI_JS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jsClass
{
public:
    QWidget *centralWidget;
    QPushButton *btncube_;
    QPushButton *btnfactorial_;
    QPushButton *btnpi_;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *jsClass)
    {
        if (jsClass->objectName().isEmpty())
            jsClass->setObjectName(QString::fromUtf8("jsClass"));
        jsClass->resize(600, 400);
        centralWidget = new QWidget(jsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btncube_ = new QPushButton(centralWidget);
        btncube_->setObjectName(QString::fromUtf8("btncube_"));
        btncube_->setGeometry(QRect(30, 80, 75, 23));
        btnfactorial_ = new QPushButton(centralWidget);
        btnfactorial_->setObjectName(QString::fromUtf8("btnfactorial_"));
        btnfactorial_->setGeometry(QRect(120, 80, 75, 23));
        btnpi_ = new QPushButton(centralWidget);
        btnpi_->setObjectName(QString::fromUtf8("btnpi_"));
        btnpi_->setGeometry(QRect(210, 80, 75, 23));
        jsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(jsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 17));
        jsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(jsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        jsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(jsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        jsClass->setStatusBar(statusBar);

        retranslateUi(jsClass);

        QMetaObject::connectSlotsByName(jsClass);
    } // setupUi

    void retranslateUi(QMainWindow *jsClass)
    {
        jsClass->setWindowTitle(QApplication::translate("jsClass", "js", 0, QApplication::UnicodeUTF8));
        btncube_->setText(QApplication::translate("jsClass", "cube", 0, QApplication::UnicodeUTF8));
        btnfactorial_->setText(QApplication::translate("jsClass", "factorial", 0, QApplication::UnicodeUTF8));
        btnpi_->setText(QApplication::translate("jsClass", "pi", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class jsClass: public Ui_jsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JS_H
