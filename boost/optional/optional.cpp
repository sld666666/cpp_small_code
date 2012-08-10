// optional.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <boost/optional.hpp>
#include <iostream>

using namespace std;


void voidTest()
{
	boost::optional<int> intOp0;
	int i = 10;
	boost::optional<int> intOp1(i);

	bool test = (NULL == intOp0);
	test = (NULL == intOp1);

	cout << intOp0 << endl;
	cout << intOp1 << endl;
	intOp1 = 13;
	cout << intOp1.get()<<endl;
	//cout << intOp0.get()<<endl;


}

int _tmain(int argc, _TCHAR* argv[])
{
	voidTest();
	return 0;
}

