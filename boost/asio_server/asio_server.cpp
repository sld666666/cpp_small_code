// asio_server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>

using namespace boost::asio;
using boost::system::error_code;
using ip::tcp;
using namespace boost;


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

class AsyncService{
public:
	AsyncService(io_service& iosev)
		: iosev_(iosev)
		, acceptor_(iosev, tcp::endpoint(tcp::v4(), 1000))
	{
		
	}

	void start()
	{
		shared_ptr<tcp::socket> socket(new tcp::socket(iosev_));
		acceptor_.async_accept(*socket
			, bind(&AsyncService::acceptHandler, this, socket));
	}

	void acceptHandler(shared_ptr<tcp::socket> psocket)
	{
		// 继续等待连接
		start();
		// 显示远程IP
		std::cout << psocket->remote_endpoint().address() << std::endl;
	}

private:
	io_service& iosev_;
	ip::tcp::acceptor acceptor_;
};

int _tmain(int argc, _TCHAR* argv[])
{
	io_service iosev;
	AsyncService service(iosev);
	service.start();
	iosev.run();
	return 0;
}

