#pragma once

class CountSort
{
public:
	static int indexInCounts(const vector<int>& vec, int index)
	{
		return vec[index]-1;
	}
	static void sortInc(vector<int>& vec, int max)
	{
		vector<int>counts(max, 0);
		vector<int>tmp(vec.size(), 0);

		for (int i = 0; i < vec.size(); ++i)
		{
			int index = indexInCounts(vec, i);
			counts[index] += 1;
		}

		for (int i = 1; i < counts.size();++i)
		{
			counts[i] = counts[i]+counts[i-1];
		}

		for (int i = (vec.size()-1); i >= 0; --i)
		{
			int indexOfCounts = indexInCounts(vec, i);
			int index = counts[indexOfCounts];
			tmp[index-1] = vec[i];
			counts[indexOfCounts] -= 1;
		}

		vec = tmp;
	}
};

static void testFun_CountSort()
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};
	vector<int> vec(nodes, nodes+sizeof(nodes)/sizeof(int));
	CountSort().sortInc(vec, 11);
	std::for_each(vec.begin(), vec.end(), cout<<lambda::_1 <<lambda::constant(","));
	cout <<endl;
}