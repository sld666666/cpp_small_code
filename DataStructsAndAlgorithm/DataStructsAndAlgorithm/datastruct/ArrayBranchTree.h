#pragma once
#include "../base.h"

class ArrayBranchTree
{
public:
	ArrayBranchTree(void);
	~ArrayBranchTree(void);
	
	void maxHeapity(vector<int>& vec, int index, int legth);
	void buildMaxHeapity(vector<int>& vec);
	
};

static void testFun_ArrayBranchTree()
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};
	
	vector<int> heap(nodes, nodes+sizeof(nodes)/sizeof(int));
	ArrayBranchTree().buildMaxHeapity(heap);
	std::for_each(heap.begin(), heap.end(), cout<<lambda::_1 <<lambda::constant(","));
	cout << endl;

	
}
