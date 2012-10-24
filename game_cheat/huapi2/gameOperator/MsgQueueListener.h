#pragma once
#include "interprocessConstant.h"
#include "log.h"
 
class MsgQueueListener
{
public:
	MsgQueueListener(void);
	~MsgQueueListener(void);

	void		start();
private:
	void		onLisnten();
	void		doOperator(MSG_QUEUE_TYPE type);
private:
	interprocess::message_queue msgQueue_;
};
