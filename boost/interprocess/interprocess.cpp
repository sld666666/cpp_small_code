// interprocess.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <boost/interprocess/shared_memory_object.hpp> 
#include <boost/interprocess/mapped_region.hpp> 
#include <boost/interprocess/ipc/message_queue.hpp>  
#include <iostream>
#include <vector>
#include <boost/thread.hpp>


using namespace boost;

void sharedMemoryTest()
{
	interprocess::shared_memory_object shdmem(interprocess::open_or_create
		, "hello", interprocess::read_write); 
	shdmem.truncate(1024); 
	interprocess::mapped_region regionWrite(shdmem, interprocess::read_write); 
	std::cout << std::hex << "0x" << regionWrite.get_address() << std::endl; 
	std::cout << std::dec << regionWrite.get_size() << std::endl; 

	int* val = static_cast<int*>(regionWrite.get_address());
	*val =  99;

	interprocess::mapped_region regionRead(shdmem, interprocess::read_only); 
	int* val2 = static_cast<int*>(regionRead.get_address());
	std::cout<<*val2<<std::endl;
}

void sharedMemoryCreate()
{
	interprocess::shared_memory_object::remove("hello"); 

	interprocess::shared_memory_object sharedObj(boost::interprocess::open_or_create, "hello"
		, boost::interprocess::read_write);

	sharedObj.truncate(1024);

	std::cout << sharedObj.get_name() << std::endl; 
	boost::interprocess::offset_t size; 
	if (sharedObj.get_size(size)) 
		std::cout << size << std::endl; 

	sharedMemoryTest();

}

void	messageQueue()
{
	try {

		interprocess::message_queue::remove("message_queue");

		interprocess::message_queue msgQueue(interprocess::open_or_create
			, "message_queue", 100, sizeof(int));

		for (int i = 0; i < 100; ++i)
		{
			msgQueue.send(&i, sizeof(i), 0);
		}

	}
	catch(interprocess::interprocess_exception &ex)
	{
		std::cout << ex.what() <<std::endl;
	}
}

void messageQueueTest()
{
	try{

		interprocess::message_queue msgQueue(interprocess::open_only
			, "sld_test");

		unsigned int prioity, recvd_size;
		//interprocess::message_queue::size_type recvd_size;

// 		for (int i = 0; i < 100; ++i)
// 		{
			int number;
			msgQueue.receive(&number, sizeof(number), recvd_size, prioity);
			std::cout << number << ",";
//		}
	}
	catch(interprocess::interprocess_exception &ex)
	{
		interprocess::message_queue::remove("message_queue");
		std::cout << ex.what() <<std::endl;
	}
}

void onLisnten()
{
	while (1)
	{
		messageQueueTest();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	
// 	messageQueue();
// 	messageQueueTest();
	thread lisntenThread(&onLisnten);
	lisntenThread.join();
	return 0;
}

