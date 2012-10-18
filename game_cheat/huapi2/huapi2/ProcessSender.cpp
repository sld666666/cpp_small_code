#include "ProcessSender.h"


ProcessSender::ProcessSender(void)
: msgQueue_(interprocess::create_only
			, INTERPRCESS_MESSAGE_QUEUE_NAME, 1, sizeof(int))
{
}

ProcessSender::~ProcessSender(void)
{
	interprocess::message_queue::remove(INTERPRCESS_MESSAGE_QUEUE_NAME);

}

void ProcessSender::sendMessageQueue()
{
	int i (1);
	msgQueue_.send(&i, sizeof(i), 0);
}
