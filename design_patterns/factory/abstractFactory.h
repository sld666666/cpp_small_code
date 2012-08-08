/** 
* @file         abstractFactory.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         8:8:2012  
*/
#pragma 
#include "item.h"

class AbstractFactory
{
public:
	AbstractFactory(){}
	virtual~AbstractFactory(){}

	virtual shared_ptr<Pizza> createPizza() = 0;
	virtual shared_ptr<Milk> createMilk() = 0;
};

class AAbstractFactory
{
public:
	AAbstractFactory(){}
	virtual~AAbstractFactory(){}

	shared_ptr<Pizza> createPizza()
	{
		return shared_ptr<CheesePizza>(new CheesePizza());
	}

	shared_ptr<Milk> createMilk()
	{
		return shared_ptr<Milk>(new Yogurt());
	}
};

class BAbstractFactory
{
public:
	BAbstractFactory(){}
	virtual~BAbstractFactory(){}

	shared_ptr<Pizza> createPizza()
	{
		return shared_ptr<GreekPizza>(new GreekPizza());
	}

	shared_ptr<Milk> createMilk()
	{
		return shared_ptr<Milk>(new Yogurt());
	}
};