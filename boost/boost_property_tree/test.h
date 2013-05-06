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

class Test
{
public:
	Test()
	{

	}

	static int* getTest()
	{
		if (!test_) test_ = new int;

		return test_;
	}
private:
	static int* test_;
};

int* Test::test_(NULL);