#pragma once

#include "../gameOperator/interprocessConstant.h"

class ProcessSender
{
public:
	ProcessSender(void);
	~ProcessSender(void);

	void	sendMessageQueue();
	
private:
	interprocess::message_queue msgQueue_;

};
