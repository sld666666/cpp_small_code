#pragma once
#include "../datastruct/ArrayBranchTree.h"
#include "base.h"

class HeapSort
{
public:

	void sortInc(vector<int>& vec)
	{
		ArrayBranchTree bTree;
		bTree.buildMaxHeapity(vec);

		for (int i = vec.size(); i > 1; --i )
		{
			swap(vec[0], vec[i-1]);
			bTree.maxHeapity(vec, 0, i-2);
		}
	}
};

static void testFun_HeapSort()
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};
	vector<int> heap(nodes, nodes+sizeof(nodes)/sizeof(int));
	HeapSort().sortInc(heap);
	std::for_each(heap.begin(), heap.end(), cout<<lambda::_1 <<lambda::constant(","));

}