#ifndef JS_H
#define JS_H

#include <QtGui/QMainWindow>
#include "ui_js.h"

class js : public QMainWindow
{
	Q_OBJECT

public:
	js(QWidget *parent = 0, Qt::WFlags flags = 0);
	~js();

private slots:
	void	OnCubeClickedSlot();
	void	OnfactorialClickedSlot();
	void	OnpiClickedSlot();

private:
	Ui::jsClass ui;
};

#endif // JS_H
