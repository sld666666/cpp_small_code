#ifndef DOPROJECT_H
#define DOPROJECT_H

#include <QtGui/QMainWindow>
#include "ui_doproject.h"

class doProject : public QMainWindow
{
	Q_OBJECT

public:
	doProject(QWidget *parent = 0, Qt::WFlags flags = 0);
	~doProject();

private:
	Ui::doProjectClass ui;
};

#endif // DOPROJECT_H
