#pragma once

#define BOOST_TEST_MODULE ArrayBranchTreeTestor
#include <boost/test/included/unit_test.hpp>
#include "../datastruct/ArrayBranchTree.h"

BOOST_AUTO_TEST_SUITE (ArrayBranchTreeTestor) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (test1)
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};

	vector<int> heap(nodes, nodes+sizeof(nodes)/sizeof(int));
	ArrayBranchTree().buildMaxHeapity(heap);

	for (int i = 0; i < heap.size()/2; ++i)
	{
		int node = heap[i];

		int index = 2*i+1;
		if (index > heap.size()-1)break;
		int left = heap[index];

		index = 2*i+2;
		if (index > heap.size()-1)break;
		int right = heap[2*i+2];

		BOOST_CHECK(node > left);
		BOOST_CHECK(node > left);
	}
}

BOOST_AUTO_TEST_SUITE_END( )