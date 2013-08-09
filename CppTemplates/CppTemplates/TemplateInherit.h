#pragma once

#include "stdafx.h"

class EmptyClass
{
	typedef int Int;
};

class EmptytToo : public EmptyClass
{

};

class NoEmpty : public EmptyClass, public EmptytToo
{

};


void testTemplateInherit()
{
	cout <<sizeof(EmptyClass)<<endl;
	cout <<sizeof(EmptytToo)<<endl;
	cout <<sizeof(NoEmpty)<<endl;
}