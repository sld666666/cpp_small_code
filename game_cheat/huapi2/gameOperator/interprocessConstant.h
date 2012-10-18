#pragma  once

#include <boost/interprocess/shared_memory_object.hpp> 
#include <boost/interprocess/mapped_region.hpp> 
#include <boost/interprocess/ipc/message_queue.hpp>  
#include <string>

using namespace boost;
using namespace std;

static const char * INTERPRCESS_MESSAGE_QUEUE_NAME		= "huapi2_message_queue";

enum MSG_QUEUE_TYPE
{
	MQT_START = 0,
	MQT_PAUSE,
};

enum TIMER_TYPE
{
	TT_MSGCHEACKER = 1
};