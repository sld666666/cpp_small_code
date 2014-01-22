// boost_lambda.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/if.hpp>
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

	for_each(a.begin(), a.end(), std::cout<<constant(' ')<< boost::lambda::_1 <<  "\n");
}

int  foo(int x)
{
	return 3*x;
}

void testFunction_3()
{
	vector<int> v(10);
	for_each(v.begin(), v.end(), _1 = 1);
	for_each(v.begin(), v.end(), cout<< _1 << "\n");
	//表达式 _1 = 1 创建一个 lambda 仿函数，它将 v 中的每一元素赋值为 1

	vector<int*> v2(10);
	transform(v.begin(), v.end(), v2.begin(), &_1);
	for_each(v2.begin(), v2.end(), cout<<*_1<<"\n");
	//表达式 &_1 创建一个取得 v 中每一个元素的地址的函数对象。这些地址赋值给 vp 中的对应元素。
	
	for_each(v.begin(), v.end(), _1 = bind(foo, _1));
	for_each(v.begin(), v.end(), cout<< _1 << "\n");

	sort(v.begin(), v.end(), _1 > _2);

}

void testFunction_4()
{
	int myints[] = {32,71,12,45,26,80,53,33};
	vector<int> myvector (myints, myints+8); 
	sort(myvector.begin(), myvector.end());
	sort(myvector.begin(), myvector.end(), _1 > _2);
	//for_each(myvector.begin(), myvector.end(), cout<< _1 << "\n");
	
	int index(0);
	for_each(myvector.begin(), myvector.end(), cout<<++var(index)<<"-"<< _1 << "\n");

}

void testFunction_5()
{
	int myints[] = {32,71,12,45,26,80,53,33};
	vector<int> myvector (myints, myints+8); 
	for_each(myvector.begin(), myvector.end()
		, if_then(_1 > 45, cout << _1 <<"\n"));
}

void testFunction_6()
{
	(cout<<_1<<" "<<_2<<" "<<_3)("welcome", "to", "cn");
}

int _tmain(int argc, _TCHAR* argv[])
{
	//testFunction_0();
	testFunction_4();
	//testFunction_5();
	return 0;
}

