// iterator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class IIterator
{
public:
	virtual int* next() = 0;
	
};



class Breakfast
{
public:
	Breakfast()
	{
		array_ = new int[5];
		array_[0] = 0;
		array_[1] = 1;
		array_[2] = 2;
		array_[3] = 3;
		array_[4] = 4;
	}
	~Breakfast()
	{
		delete [] array_;
	}
private:
	int* array_;
};

class BreakfastIterator : public IIterator
{
public:
	BreakfastIterator(Breakfast breakfast)
	{
		breakfast_ = breakfast;
	}

	virtual int* next()
	{

	}
private:
	Breakfast breakfast_;
};



class Lunch
{
public:
	Lunch()
	{
		array_.push_back(0);
		array_.push_back(1);
		array_.push_back(2);
		array_.push_back(3);
		array_.push_back(4);
	}

	~Lunch()
	{

	}

private:
	vector<int> array_;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

