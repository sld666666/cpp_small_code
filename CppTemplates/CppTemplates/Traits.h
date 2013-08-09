#pragma once 
#include "stdafx.h"
template<typename T>
inline T accum(const T * begin, const T* end)
{
	T total  = T();
	while (begin != end){
		total += *begin;
		++begin;
	}

	return total;
}


void testTrait()
{
	int nums[] = {1, 2, 3, 4, 5};
	cout << accum(&nums[0], &nums[5]) << endl;

	char name[] = "template";
	int legth = sizeof(name)-1;//对char 进行实例化的时候可能会出现char越界的情况
	cout << accum(&name[0], &name[legth]) << endl;
}
////////////////////////////////////////////////

template<typename T>
class AccumTraits;

template<>
class AccumTraits<char>{
public:
	typedef int AccT;
};

template<>
class AccumTraits<int>{
public:
	typedef int AccT;
};


template <typename T>
typename AccumTraits<T>::AccT accum_1(const T * begin, const T* end)
{
	typedef typename AccumTraits<T>::AccT AccT;
	AccT total = AccT();
	while (begin != end){
		total += *begin;
		++begin;
	}

	return total;
}

void testTrait_1()
{
	int nums[] = {1, 2, 3, 4, 5};
	cout << accum_1(&nums[0], &nums[5]) << endl;

	char name[] = "template";
	int legth = sizeof(name)-1;//对char 进行实例化的时候可能会出现char越界的情况
	cout << accum_1(&name[0], &name[legth]) << endl;
}
/////////////////////////////////////////////////
struct CatTag //这只是个空类，目的是激发函数重载
{
};

struct DogTag{

};

class Dog{
public:
	typedef DogTag type;

};

class Cat{
public:
	typedef CatTag type;
};

template<typename T>
void doAccept(T dog, DogTag)
{
	cout << "dog" <<endl;
}


template<typename T>
void doAccept(T cat, CatTag)
{
	cout << "cat" << endl;
}

template<class T>
void accept(T animal)
{
	// 如果T为狗类，则typename T::type就是dog_tag，
	//那么typename T::type()就是创建了一个dog_tag类的临时对象，
	//根据函数重载的规则，这将调用Accept(T,dog_tag)，这正是转向处理狗的策略。
	//如果T为猫类，则typename T::type为cat_tag，由上面的推导，
	//这将调用Accept(T,cat_tag)，即转向处理猫的策略，
	//typename 关键字告诉编译器T::type是个类型而不是静态成员。
	doAccept(animal, typename T::type());
}


void testTrait_2()
{
	accept(Dog());
	accept(Cat());
}

template<typename T, typename AT = AccumTraits<T>>
class Accum{
public:
	static typename AT::AccT accum(T* begin, T* end)
	{
		typedef typename AT::AccT AccT;
		AccT total = AccT();
		while (begin != end){
			total += *begin;
			++begin;
		}

		return total;
	}
};	

void testTrait_3()
{
	int nums[] = {1, 2, 3, 4, 5};
	cout << Accum<int>::accum(&nums[0], &nums[5]) << endl;

	char name[] = "template";
	int legth = sizeof(name)-1;//对char 进行实例化的时候可能会出现char越界的情况
	cout <<  Accum<char>::accum(&name[0], &name[legth]) << endl;
}
