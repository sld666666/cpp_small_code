
#pragma once

#include "stdafx.h"
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const system::error_code& e)
{
	cout << "hello, world\n";
}

void fun()
{
	asio::io_service io;
	asio::deadline_timer t(io, posix_time::seconds(5));
	t.async_wait(&print);
	io.run();
}