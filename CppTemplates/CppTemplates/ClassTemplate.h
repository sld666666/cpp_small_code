#pragma once
#include "stdafx.h"

template <typename T>
class Printer{
public:
	void print(T elem);
};


template <typename T>
void Printer<T>::print(T elem)
{
	cout << elem <<endl;
}

//特化
template<>
class Printer<string>
{
public:
	void print(string elem)
	{
		cout << "string: " <<elem <<endl;
	}
};

//局部特化
template<typename T1, typename T2>
class MyClass{
public:
	void print(T1 a, T2 b)
	{
		cout << "My Class" << a  <<"," << b << endl;
	}
};

template <typename T>
class MyClass<T, int>{
public:
	void print(T a, int b)
	{
		cout << "small int" << a  <<"," << b << endl;
	}
};

template <>
class MyClass<float, int>{
public:
	void print(float a, int b)
	{
		cout << "float int" << a  <<"," << b << endl;
	}
};


//缺省模板参数
template<typename T, typename CONT = vector<T>>
class Stack{
public:
	void add(T elem){
		elems.push_back(elem);
	}
private:
	CONT elems;
};
void testClassTemplate()
{
// 	Printer<int>().print(13);
// 	Printer<string>().print("1234");
	MyClass<float, float>().print(1.0,2.0);
	MyClass<int, int>().print(1,2);
	MyClass<float, int>().print(1.0,2);
}