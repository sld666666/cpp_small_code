#ifndef QT_H
#define QT_H

#include <QtGui/QMainWindow>
#include "ui_qt.h"

class QtTest : public QMainWindow
{
	Q_OBJECT

public:
	QtTest(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtTest();

private:
	Ui::QtClass ui;
};

#endif // QT_H
