#include "qt.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Qt w;
	w.show();
	return a.exec();
}
