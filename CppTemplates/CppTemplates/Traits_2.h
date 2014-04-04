#pragma once
#include <iostream>
using namespace std;

struct no_move{};
struct has_move {};

struct ValueType{
public:
	void move(){cout <<"move a ValueType" << endl;}
};

template<typename T>
struct traits{
	typedef no_move move_method;//对于traits模板类，默认为无move方法
	void move(T* p){}//默认为无move方法
};

template <> struct 
traits<ValueType>{
	typedef has_move move_method;//对于myValueType，traits模板偏特化，定义了有move方法
	void move(ValueType* p){p->move();} //模板特化，有move方法
};

template <typename T> 
struct Container{
	void move(T* p){traits<T>().move(p);};
};

void test_06()
{
	int i=101;
	int *p1=&i;
	ValueType v1;
	ValueType *pv=&v1;
	Container<int> c1;
	Container<ValueType> c2;
	c1.move(p1);
	c2.move(pv);

}