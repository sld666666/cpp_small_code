#include <QMessageBox>
#define BOOST_ALL_NO_LIB
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "huapi2.h"
#include "../gameOperator/HookOpreator.h"
#pragma comment(lib, "boost_thread-vc90-mt-1_43.lib")

using namespace boost;

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
	connect(ui.btnHook_, SIGNAL(clicked()), this, SLOT(onHookPressed()));
	connect(ui.btnTest_, SIGNAL(clicked()), this, SLOT(onTestPressed()));
}

void huapi2::onHookPressed()
{
	installHook();
// 	start();
// 	QMessageBox::warning(this, tr("huapi2"),tr("start"));
}

void huapi2::onTestPressed()
{
	processSender_->sendMessageQueue();
}

void huapi2::start()
{
	boost::thread lisntenThread(bind(&huapi2::onLisnten, this));
	//lisntenThread.join();
}

void huapi2::onLisnten()
{
	while (1)
	{
		try{
			unsigned int prioity, recvd_size;

			int recvd_number;
			interprocess::message_queue msgQueue_(interprocess::open_only, INTERPRCESS_MESSAGE_QUEUE_NAME);
			msgQueue_.receive(&recvd_number, sizeof(recvd_number), recvd_size, prioity);
			//doOperator(static_cast<MSG_QUEUE_TYPE>(recvd_number));
			qDebug("Items in list: %d", recvd_number);
			//TRACE(recvd_number);
		}
		catch(interprocess::interprocess_exception &ex)
		{
			interprocess::message_queue::remove("message_queue");
			//std::cout << ex.what() <<std::endl;
		}
	}
}