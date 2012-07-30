#include "qt.h"

Qt::Qt(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

Qt::~Qt()
{

}
