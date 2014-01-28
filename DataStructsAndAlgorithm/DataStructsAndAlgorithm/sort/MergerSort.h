#pragma once
#include "../base.h"

class MergerSort
{
public:
	static void sortInc(vector<int>& vec)
	{
		vector<int> tmp;
		mergerSort(vec, 0, vec.size()-1, tmp);
	}

	static void mergerSort(vector<int>& vec
							, int first
							, int last
							, vector<int>& out)
	{
		if (first < last)
		{
			int mid = (first+last)/2;
			mergerSort(vec, first, mid, out);
			mergerSort(vec, mid+1, last, out);
			mergerSorted(vec, first, mid, last, out);
		}
	}

	static void mergerSorted(vector<int>& input
									, int first
									, int mid
									, int last
									, vector<int>& rtn)
	{

		int i(first), j(mid+1);
		while(i <= mid
			&& j <= last)
		{
			if (input[i] <= input[j])
			{
				rtn.push_back(input[i]);
				++i;
			}else{
				rtn.push_back(input[j]);
				++j;
			}
		}

		while(i <= mid){
			rtn.push_back(input[i]);
			++i;
		}

		while(j <= last)
		{
			rtn.push_back(input[j]);
			++j;
		}

		for (int i = 0; i < rtn.size(); ++i)
		{
			input[first+i]= rtn[i];
		}

		rtn.clear();
	}

};

static void testFun_MergerSort()
{
	int nodes []= {1,10,11,7,9,3,4,5,2,4,5,6};
	vector<int> vec(nodes, nodes+sizeof(nodes)/sizeof(int));
	MergerSort().sortInc(vec);
	std::for_each(vec.begin(), vec.end(), cout<<lambda::_1 <<lambda::constant(","));
	cout <<endl;
}