#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "ui_login.h"
#include "login_global.h"

class LOGIN_EXPORT Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = 0);
	~Login();

private:
	Ui::Login ui;
};

#endif // LOGIN_H
