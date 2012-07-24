// boost_lambda_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <boost/lambda/lambda.hpp>
#include <iostream>


using namespace std;
using namespace boost::lambda;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(i*6);
	}

	for_each(vec.begin(), vec.end()
		, cout << _1 << ' ');

	return 0;
}

