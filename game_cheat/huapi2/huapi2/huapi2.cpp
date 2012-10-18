#include "huapi2.h"
#include "../gameOperator/HookOpreator.h"

huapi2::huapi2(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	initConnect();

	interprocess::message_queue::remove(INTERPRCESS_MESSAGE_QUEUE_NAME);
	processSender_ = shared_ptr<ProcessSender>(new ProcessSender());
}

huapi2::~huapi2()
{

}

void huapi2::initConnect()
{
	connect(ui.btnHook_, SIGNAL(pressed()), this, SLOT(onHookPressed()));
	connect(ui.btnTest_, SIGNAL(pressed()), this, SLOT(onTestPressed()));
}

void huapi2::onHookPressed()
{
	installHook();
}

void huapi2::onTestPressed()
{
	processSender_->sendMessageQueue();
	doOperator(MQT_START);
}