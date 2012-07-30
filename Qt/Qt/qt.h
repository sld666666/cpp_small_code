#ifndef QT_H
#define QT_H

#include <QtGui/QMainWindow>
#include "ui_qt.h"

class Qt : public QMainWindow
{
	Q_OBJECT

public:
	Qt(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Qt();

private:
	Ui::QtClass ui;
};

#endif // QT_H
