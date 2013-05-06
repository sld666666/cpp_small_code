// std_sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace  std;

bool compare(int a,int b)
{
	return a < b;
}
bool compare1(int a,int b)
{
	return a > b;
}

void test_0()
{
	vector<int> vec;
	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(8);
	vec.push_back(10);
	vec.push_back(48);
	vec.push_back(32);
	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(3);

	sort(vec.begin(), vec.end(), compare);
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	sort(vec.begin(), vec.end(), compare1);
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ","));

}

struct STTEST 
{
	string name;
	long id;
	STTEST(string _name, long _id){
		name = _name;
		id = _id;
	}
};

bool structCompare0(STTEST first, STTEST second){
	return first.id < second.id;
}

bool structCompare1(STTEST first, STTEST second){
	return first.id > second.id;
}
void printSTTEST(STTEST stTest)
{
	cout << stTest.name << ",";
}
void test_1()
{
	vector<STTEST> vec;
	vec.push_back(STTEST("111", 1));
	vec.push_back(STTEST("222", 2));
	sort(vec.begin(), vec.end(), structCompare0);
	for_each(vec.begin(), vec.end(), printSTTEST);
	cout << endl;

	sort(vec.begin(), vec.end(), structCompare1);
	for_each(vec.begin(), vec.end(), printSTTEST);
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	test_1();
	return 0;
}

