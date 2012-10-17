#include "huapi2.h"
#include "../gameOperator/HookOpreator.h"

huapi2::huapi2(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	initConnect();
}

huapi2::~huapi2()
{

}

void huapi2::initConnect()
{
	connect(ui.btnHook_, SIGNAL(pressed()), this, SLOT(onHookPressed()));
}

void huapi2::onHookPressed()
{
	installHook();
}