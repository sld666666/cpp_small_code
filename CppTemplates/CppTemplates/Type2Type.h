#pragma  once

template <typename T>
struct Type2Type
{
	typedef T OriginalType;
};

template<typename T, class U>
T* create(const U& arg, Type2Type<T>)
{
	return new T(arg);
}

template <class U>
Widget* create(const U& arg, Type2Type<Widget>)
{
	return new Widget(arg, -1);
}

void test_05()
{
	string* pStr = create("Hello", Type2Type<string>());
	Widget* pW = create(100, Type2Type<Widget>());
}