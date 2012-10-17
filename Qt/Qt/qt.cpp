#include "qt.h"

QtTest::QtTest(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

QtTest::~QtTest()
{

}
