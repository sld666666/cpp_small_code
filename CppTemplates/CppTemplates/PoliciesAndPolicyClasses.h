#pragma once
#include <iostream>

template <typename T>
struct OpNewCreator
{
	static T* create()
	{
		return new T();
	}
};


template <typename T>
struct MallocCreator
{
	static T* create()
	{
		void* buf = std::malloc(sizeof(T));
		if(!buf)return 0;
		return buf;
	}
};

template <typename CreationPolicy>
class WidgetManager : public CreationPolicy
{

};

class Widget
{
public:
	Widget()
	{
		std::cout << "Widget" << std::endl;
	}
};

void test_0()
{
	typedef WidgetManager<OpNewCreator<Widget>> OpWidgetManager;
	OpWidgetManager manager;
	manager.create();
}