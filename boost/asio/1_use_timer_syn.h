
#pragma once

#include "stdafx.h"
#include <boost/date_time/posix_time/posix_time.hpp>

void fun()
{
	asio::io_service io;

	asio::deadline_timer t(io, posix_time::seconds(5));
	t.wait();
	cout<< "hello, world\n";

}