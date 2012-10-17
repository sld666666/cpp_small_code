#ifndef HUAPI2_H
#define HUAPI2_H

#include <QtGui/QMainWindow>
#include "ui_huapi2.h"

class huapi2 : public QMainWindow
{
	Q_OBJECT

public:
	huapi2(QWidget *parent = 0, Qt::WFlags flags = 0);
	~huapi2();

private:
	void	initConnect();

private slots:
	void	onHookPressed();

private:
	Ui::huapi2Class ui;
};

#endif // HUAPI2_H
