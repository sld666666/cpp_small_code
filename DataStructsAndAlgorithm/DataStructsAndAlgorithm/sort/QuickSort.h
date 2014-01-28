#pragma once
#include "../base.h"

class QuickSort{

public:
	static void sortInc(vector<int>& vec)
	{
		doSortInc(vec, 0, vec.size()-1);
	}

	static void doSortInc(vector<int>& vec, int begin, int end)
	{
		if (begin < end){
			int pos = parition(vec, begin, end);
			doSortInc(vec, begin, pos-1);
			doSortInc(vec, pos+1, end);
		}
	}

	static int parition(vector<int>& vec, int begin, int end)
	{
		int compared = vec[end];
		int i = begin -1;

		for (int j = begin; j < end; ++j)
		{
			if (vec[j] <= compared)
			{
				++i;
				std::swap(vec[i], vec[j]);
			}
		}

		std::swap(vec[i+1], vec[end]);

		return ++i;
	}
};

static void testFun_QuickSort()
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};
	vector<int> vec(nodes, nodes+sizeof(nodes)/sizeof(int));
	QuickSort().sortInc(vec);
	std::for_each(vec.begin(), vec.end(), cout<<lambda::_1 <<lambda::constant(","));
	cout <<endl;
}