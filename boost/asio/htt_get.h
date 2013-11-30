#pragma once

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>

using namespace boost::asio;
using boost::system::error_code;
using ip::tcp;
using namespace boost;

void printHtml()
{
	io_service iosev;
	ip::tcp::resolver res(iosev);
	ip::tcp::resolver::query query("www.baidu.com","80"); //www.163.com 80端口
	ip::tcp::resolver::iterator itr_endpoint = res.resolve(query);
	ip::tcp::resolver::iterator itr_end; //无参数构造生成end迭代器
	ip::tcp::socket socket(iosev);
	boost::system::error_code ec = error::host_not_found;
	for(;ec && itr_endpoint!=itr_end;++itr_endpoint)
	{
		socket.close();
		socket.connect(*itr_endpoint, ec);
	}

	if(ec){
		std::cout << boost::system::system_error(ec).what() << std::endl;
	}

	socket.write_some(buffer("GET <a href=\"www.baidu.com\" title=\"http://www.baidu.com\">\
 							 http://www.baidu.com</a> HTTP/1.0 "));
	for(;;)
	{
		char buf[128];
		boost::system::error_code error;
		size_t len = socket.read_some(buffer(buf), error);
		// 循环取数据，直到取完为止
		if(error == error::eof)
			break;
		else if(error)
		{
			std::cout << boost::system::system_error(error).what() << std::endl;
		}

		std::cout.write(buf, len);
	}
}