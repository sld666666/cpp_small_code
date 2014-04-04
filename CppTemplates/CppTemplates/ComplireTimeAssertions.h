#pragma once
#include <iostream>
using namespace std;


#define STATIC_CHECK(expr) { char unnamed[(expr) ? 1 : 0]; }

template<typename To, typename From>
To safeReinterpret_cast(From from)
{
	STATIC_CHECK(sizeof(From) <= sizeof(To));
	return reinterpret_cast<To>(from);
}

class Base{};
class Sub : public Base{
private:
	int a;
};

template<bool> struct CompileTimeError;
template<> struct CompileTimeError<true>{};

#define STATIC_CHECK_EX(expr)\
	(CompileTimeError<(expr) != 0>)

template<bool> struct CompileTimeChecker2
{
	CompileTimeChecker2(...){}
};

template<> struct CompileTimeChecker2<false>{};

#define STATIC_CHECK_EX2(expr, msg)\
{\
class ERROR_##msg{};\
(void)sizeof(CompileTimeChecker2><expr>(ERROR_##msg()));\
}

void test_3()
{
	cout << sizeof(Base)<<endl;;
	cout << sizeof(Sub)<<endl;
 	void* base = new Base();
// 	char b = safeReinterpret_cast<char>(base);
// 	CompileTimeError<false> a;
// 	CompileTimeError<true> b;
}