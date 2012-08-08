// factory.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "simple_factory.h"
#include "abstractFactory.h"
#include "factoryMothod.h"


int _tmain(int argc, _TCHAR* argv[])
{
// 	shared_ptr<Pizza> cheesePizza = PizzaFactory::createPizza(PIZZA_TYPE_CHEESE); 
// 	shared_ptr<Pizza> greekPizza = PizzaFactory::createPizza(PIZZA_TYPE_GREEK); 
// 	shared_ptr<Pizza> pepperoniPizza = PizzaFactory::createPizza(PIZZA_TYPE_PEPPERONI);

// 	cheesePizza->MakePizza(); 
// 	greekPizza->MakePizza(); 
// 	pepperoniPizza->MakePizza(); 

// 	shared_ptr<Pizza> cheesePizza = BAbstractFactory().createPizza();
// 	cheesePizza->MakePizza();

	shared_ptr<FactoryMethod> mothod (new CheeseFactoryMethod()); 
	shared_ptr<Pizza>cheesePizza = mothod->MakePizza();
	cheesePizza->MakePizza();

	return 0;
}

