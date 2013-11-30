// asio_server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <boost/asio.hpp>


void run(){
	
	using namespace boost::asio;
	
	io_service iosev;
	ip::tcp::acceptor acceptor(iosev
		, ip::tcp::endpoint(ip::tcp::v4(), 1000));
	while(1){
		ip::tcp::socket socket(iosev);
		acceptor.accept(socket);
		std::cout << socket.remote_endpoint().address()<<std::endl;
		boost::system::error_code ec;
		socket.write_some(buffer("hello world!"), ec);
		if(ec)
		{
			std::cout << 
				boost::system::system_error(ec).what() << std::endl;
			break;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	run();
	return 0;
}

