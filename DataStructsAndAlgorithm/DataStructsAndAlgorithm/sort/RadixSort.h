#pragma once
#include "../base.h"

class RadixSort
{
public:
	static int getOne(int num)
	{
		return num%10;
	}

	static int getN(int num,int n)
	{
		if(n == 1)
			return getOne(num);
		int div = 1;
		for(int i = 1; i < n;i++)
			div *= 10;
		int ret = num/div;
		return getOne(ret);
	}

	static void sortInc(vector<int>& vec, int maxMedian)
	{
		for (int i = 1; i <= maxMedian; ++i)
		{
			sortInByMedian(vec, i);
		}
	}

	static void sortInByMedian(vector<int>& vec, int n)
	{
		for (int i = 1; i < vec.size(); ++i)
		{
			int tmp = i;
			int key = sortedMoveInc(vec, tmp, n);
			
			vec[tmp+1] = key;
		}	 
	}
		//²åÈëÅÅÐò
	static int sortedMoveInc(vector<int>& source, int& curIndex ,int n)
	{
		int rtn = source[curIndex];
		int key = getN(source[curIndex], n);
		int j = curIndex -1;
		while(j >=0  && key <  getN(source[j],n))
		{
			source[j+1]=source[j];
			j--;
		}

		curIndex = j;
		return rtn;
	}
};

static void testfun_RadixSort()
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};
	vector<int> vec(nodes, nodes+sizeof(nodes)/sizeof(int));
	RadixSort().sortInc(vec,2);
	std::for_each(vec.begin(), vec.end(), cout<<lambda::_1 <<lambda::constant(","));
	cout <<endl;
}