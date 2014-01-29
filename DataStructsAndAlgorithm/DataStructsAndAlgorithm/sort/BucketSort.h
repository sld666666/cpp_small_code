#pragma once
#include "../base.h"
class BucketSort
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
		vector<vector<int>> buckets(10);
		for (int i = 0; i < vec.size(); ++i)
		{
			int median = getN(vec[i], maxMedian);
			buckets[median].push_back(vec[i]);
		}

		vec.clear();
		for (vector<vector<int>>::iterator iter = buckets.begin()
			; iter != buckets.end(); ++iter)
		{
			vector<int> bucketItems = *iter;
			sort(bucketItems.begin(), bucketItems.end());
			for (vector<int>::iterator pos = bucketItems.begin()
				; pos != bucketItems.end(); ++pos)
			{
				vec.push_back(*pos);
			}
		}
	}
};

static void testFun_BucketSort()
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};
	vector<int> vec(nodes, nodes+sizeof(nodes)/sizeof(int));
	BucketSort().sortInc(vec, 2);
	std::for_each(vec.begin(), vec.end(), cout<<lambda::_1 <<lambda::constant(","));
	cout <<endl;
}