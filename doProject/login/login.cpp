#include "login.h"
#include "loginConstant.h"

Login::Login(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.webView_->load(QUrl(LOGIN_URL));
	ui.webView_->show();
}

Login::~Login()
{

}
