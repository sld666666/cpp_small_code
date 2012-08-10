// boost_lambda.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <algorithm>
#include <vector>

using namespace std;
using namespace boost::lambda;

//一般情况下
void print(int i)   
{   
	std::cout << i << std::endl;   
} 
void testFunction_0()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for_each(a.begin(), a.end(), print);
}

//。从而省去增加一个函数的需要。另外一个好处是代码更为紧凑
//，使得算法与负责数据输出的函数不是局部性分离的。Boost.Lambda正好使之成为现实

void testFunction_2()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for_each(a.begin(), a.end(), std::cout<< boost::lambda::_1 <<  "\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
	testFunction_0();
	testFunction_2();
	return 0;
}

