#pragma once
#include <boost/function.hpp>
#include <boost/lambda/lambda.hpp>
#include <iostream>

using namespace boost;
using namespace boost::lambda;
using namespace std;

typedef function<bool(int, int)> ComparedFun;
class InsertSorter
{
public:
	
	void sort(int* source, int size, bool inc = true)
	{
		for (int i = 1; i < size; ++i)
		{
			int tmp = i;
			int key;
			if (inc)
				key	= sortedMoveInc(source, tmp);
			else
				key = sortedMoveDesc(source, tmp);

			source[tmp+1] = key;
		}
	}
private:
	int sortedMoveInc(int*& source, int& curIndex)
	{
		int key = source[curIndex];
		int j = curIndex -1;
		while(j >=0  && key < source[j])
		{
			source[j+1]=source[j];
			j--;
		}

		curIndex = j;
		return key;
	}

	int sortedMoveDesc(int*& source, int& curIndex)
	{
		int key = source[curIndex];
		int j = curIndex -1;
		while(j >=0  && key > source[j])
		{
			source[j+1]=source[j];
			j--;
		}

		curIndex = j;
		return key;
	}
};

void testFun_Insertsort()
{
	 int arr[] = {5, 2, 4, 6, 1, 3};;
	 InsertSorter().sort(arr, sizeof arr/ sizeof arr[0]);
	 for(int i = 0; i <  sizeof arr/ sizeof arr[0]; ++i){
		 cout << arr[i] <<",";
	 }

	 cout << endl;
	 InsertSorter().sort(arr, sizeof arr/ sizeof arr[0], false);
	 for(int i = 0; i <  sizeof arr/ sizeof arr[0]; ++i){
		 cout << arr[i] <<",";
	 }
}