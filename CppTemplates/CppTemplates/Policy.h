#pragma once

#include "stdafx.h"
template<typename T>
class AccumTraits;

template<>
class AccumTraits<int>{
public:
	typedef int AccT;
};

class SumPolicy{
public:
	template<typename T>
	static void accum(T& val, T& total){
		total += val;
	} 
};

class MultPolicy{
public:
	template<typename T>
	static void accum(T& val, T& total){
		total *= val;
	} 
};

template <typename T
		, typename Policy = SumPolicy
		, typename Traits = AccumTraits<T>>
class Accum
{
public:
	typedef typename Traits::AccT AccT;
	static AccT accum(T* begin, T*end)
	{
		AccT total = AccT();
		while(begin != end){
			Policy::accum(*begin, total);
			++begin;
		}

		return total;
	}
};

void testPolicy()
{
	int nums[] = {1, 2, 3, 4, 5};
	cout << Accum<int>::accum(&nums[0], &nums[5]) << endl;

	cout << Accum<int, MultPolicy>::accum(&nums[0], &nums[5]) << endl;
}