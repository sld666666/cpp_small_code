#pragma once

#define BOOST_TEST_MODULE HeapSortTestor
#include <boost/test/included/unit_test.hpp>
#include "../sort/HeapSort.h"

BOOST_AUTO_TEST_SUITE (HeapSortTestor) // name of the test suite is 

BOOST_AUTO_TEST_CASE (test1)
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};

	vector<int> heap(nodes, nodes+sizeof(nodes)/sizeof(int));
	HeapSort().sortInc(heap);

	for (int i = 1; i < heap.size()-1; ++i)
	{
		BOOST_CHECK(heap[i] <= heap[i+1]);

	}
}

BOOST_AUTO_TEST_SUITE_END( )