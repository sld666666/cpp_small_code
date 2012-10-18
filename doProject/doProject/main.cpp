#include "doproject.h"
#include <QtGui/QApplication>

#include "login.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Login login;
	//if (QDialog::Accepted == login.exec())
	{
		doProject w;
		w.show();
		return a.exec();
	}

	return 0;
	
}
