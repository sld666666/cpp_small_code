// thread.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost/thread.hpp>
#include <iostream>

using namespace boost;
using namespace std;

void hello()
{
	cout << "hello !!" <<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	thread mythread(&hello);
	mythread.join();
	return 0;
}

