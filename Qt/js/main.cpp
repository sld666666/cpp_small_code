#include "js.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	js w;
	w.show();
	return a.exec();
}
