// boost_tuple.cpp : 定义控制台应用程序的入口点。
//

/** 
* @file         boost_tuple.cpp 
* @Synopsis     tuple的摸底和pair 类似， 但是能支持2个以上的类型 
* @author       diwu.sld 
* @version     	1.0
* @date         2012-7-23
*/

#include "stdafx.h"
#include <boost/tuple/tuple.hpp>
#include <iostream>
#include <boost/tuple/tuple_io.hpp>

using namespace boost;
using namespace  std;


//在使用元组时，务必牢记以下事实：
//1.能够形成元组的元素数量目前仅限于 10 个。
//2. 元组可以包含用户定义的类类型，但是您必须负责确保那些类已经定义了正确的构造函数和拷贝构造函数 (copy constructor)

void funTest_0()
{
	tuple<int, char, float> t(2, 'a', 0.9);
	cout<< t << endl;
}

//与 STL 提供的 make_pair 函数非常类似，Boost 提供了 make_tuple 例程。
//要从函数返回元组，您必须调用 make_tuple。可以创建具有临时元素的元组；

void funTest_1()
{
	tuple<int ,int> t = make_tuple<int, int>(10, 20);
	cout << t.get<0>() <<endl;

	get<0>(t) = 11;
	++get<0>(t);
	cout <<t.get<0>()<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	funTest_0();
	funTest_1();
	return 0;
}

