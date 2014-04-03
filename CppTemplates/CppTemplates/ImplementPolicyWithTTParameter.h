#pragma once

#include "PoliciesAndPolicyClasses.h"
class Gadget{
public:
	Gadget()
	{
		std::cout<<"Gadget"<<std::endl;
	}
};

template<template<typename Creator> class CreationPolicy>
class WidgetManagerEx : public CreationPolicy<Widget>
{
public:
	void doSomething()
	{
		Gadget* gadget = CreationPolicy<Gadget>::create();
	}
};


void test_1()
{
	typedef WidgetManagerEx<OpNewCreator> OpWidgetManager;
	OpWidgetManager manager;
	manager.create();
	manager.doSomething();
}