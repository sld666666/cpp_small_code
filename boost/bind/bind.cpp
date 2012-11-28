// bind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <functional>
#include <boost/bind.hpp>
#include <algorithm>

using namespace std;
using namespace boost;

void fun_1()
{
	vector<int> vecs;
	vecs.push_back(7);
	vecs.push_back(4);
	vecs.push_back(12);
	vecs.push_back(10);

	int counts = count_if(vecs.begin()
						, vecs.end()
						, bind(logical_and<bool>()
						, bind(greater<int>(), _1, 5)
						, bind(less_equal<int>(),_1, 10)));
					

	cout << counts<<endl;
}

void fun_2()
{
	vector<double> values; 
	values.push_back(10.0); 
	values.push_back(100.0); 
	values.push_back(1000.0); 

	copy(values.begin(), values.end(), ostream_iterator<double>(std::cout," "));

	transform(values.begin(), values.end(), values.begin()
		, bind(multiplies<double>(), 0.90
		, bind(multiplies<double>(), _1, 1.10)));

	copy(values.begin(), values.end(), ostream_iterator<double>(std::cout," "));
}

int _tmain(int argc, _TCHAR* argv[])
{
	fun_2();
	return 0;
}

