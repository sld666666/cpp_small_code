#ifndef HUAPI2_H
#define HUAPI2_H

#include <QtGui/QMainWindow>
#include "ui_huapi2.h"
#include "ProcessSender.h"

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
	void	onTestPressed();

private:
	Ui::huapi2Class ui;
	shared_ptr<ProcessSender>  processSender_;
};

#endif // HUAPI2_H
