/********************************************************************************
** Form generated from reading UI file 'doproject.ui'
**
** Created: Sun Sep 9 20:49:55 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOPROJECT_H
#define UI_DOPROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doProjectClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *doProjectClass)
    {
        if (doProjectClass->objectName().isEmpty())
            doProjectClass->setObjectName(QString::fromUtf8("doProjectClass"));
        doProjectClass->resize(600, 400);
        menuBar = new QMenuBar(doProjectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        doProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(doProjectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        doProjectClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(doProjectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        doProjectClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(doProjectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        doProjectClass->setStatusBar(statusBar);

        retranslateUi(doProjectClass);

        QMetaObject::connectSlotsByName(doProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *doProjectClass)
    {
        doProjectClass->setWindowTitle(QApplication::translate("doProjectClass", "doProject", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class doProjectClass: public Ui_doProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOPROJECT_H
