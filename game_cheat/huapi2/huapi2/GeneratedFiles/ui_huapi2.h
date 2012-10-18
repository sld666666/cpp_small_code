/********************************************************************************
** Form generated from reading UI file 'huapi2.ui'
**
** Created: Thu Oct 18 15:54:01 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUAPI2_H
#define UI_HUAPI2_H

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

class Ui_huapi2Class
{
public:
    QWidget *centralWidget;
    QPushButton *btnHook_;
    QPushButton *btnTest_;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *huapi2Class)
    {
        if (huapi2Class->objectName().isEmpty())
            huapi2Class->setObjectName(QString::fromUtf8("huapi2Class"));
        huapi2Class->resize(566, 419);
        centralWidget = new QWidget(huapi2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnHook_ = new QPushButton(centralWidget);
        btnHook_->setObjectName(QString::fromUtf8("btnHook_"));
        btnHook_->setGeometry(QRect(30, 20, 75, 23));
        btnTest_ = new QPushButton(centralWidget);
        btnTest_->setObjectName(QString::fromUtf8("btnTest_"));
        btnTest_->setGeometry(QRect(180, 20, 75, 23));
        huapi2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(huapi2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 566, 17));
        huapi2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(huapi2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        huapi2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(huapi2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        huapi2Class->setStatusBar(statusBar);

        retranslateUi(huapi2Class);

        QMetaObject::connectSlotsByName(huapi2Class);
    } // setupUi

    void retranslateUi(QMainWindow *huapi2Class)
    {
        huapi2Class->setWindowTitle(QApplication::translate("huapi2Class", "huapi2", 0, QApplication::UnicodeUTF8));
        btnHook_->setText(QApplication::translate("huapi2Class", "hook", 0, QApplication::UnicodeUTF8));
        btnTest_->setText(QApplication::translate("huapi2Class", "test", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class huapi2Class: public Ui_huapi2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUAPI2_H
