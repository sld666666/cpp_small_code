#pragma once
#include <iostream>
using namespace std;

class testClass
{
public:
	template<typename T> 
	T mfun(const T& t)
	{
		return t/2;
	}
};