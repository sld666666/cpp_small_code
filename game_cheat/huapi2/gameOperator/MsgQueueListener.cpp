#include "StdAfx.h"

#define BOOST_ALL_NO_LIB
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "MsgQueueListener.h"

#pragma comment(lib, "boost_thread-vc90-mt-1_43.lib")

MsgQueueListener::MsgQueueListener(void)
: msgQueue_(interprocess::open_only, INTERPRCESS_MESSAGE_QUEUE_NAME)
{
}

MsgQueueListener::~MsgQueueListener(void)
{
}

void MsgQueueListener::start()
{
	boost::thread lisntenThread(bind(&MsgQueueListener::onLisnten, this));

}

void MsgQueueListener::onLisnten()
{
	while (1)
	{
		try{
			unsigned int prioity, recvd_size;

			int recvd_number;
			msgQueue_.receive(&recvd_number, sizeof(recvd_number), recvd_size, prioity);
			doOperator(static_cast<MSG_QUEUE_TYPE>(recvd_number));
			Log::instance().debugMsg("MsgQueueListener receive", recvd_number);
		}
		catch(interprocess::interprocess_exception &ex)
		{
			interprocess::message_queue::remove("message_queue");
			//std::cout << ex.what() <<std::endl;
		}
	}
}


void MsgQueueListener::doOperator(MSG_QUEUE_TYPE type)
{
	switch(type)
	{
	case MQT_START:
		break;
	case MQT_PAUSE:
		break;
	default:
		break;
	}
}
