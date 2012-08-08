/** 
* @file         simple_factory.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         8:8:2012  
*/
#pragma  once
#include "item.h"



class PizzaFactory 
{ 
public: 
	PizzaFactory(){}; 
	~PizzaFactory(){};

	static shared_ptr<Pizza> createPizza(PIZZA_TYPE pizzaType) 
	{ 
		switch (pizzaType) 
		{ 
		case PIZZA_TYPE_CHEESE: 
			return shared_ptr<Pizza>(new CheesePizza()); 
		case PIZZA_TYPE_GREEK: 
			return shared_ptr<Pizza>(new GreekPizza()); 
		case PIZZA_TYPE_PEPPERONI: 
			return shared_ptr<Pizza>(new PepperoniPizza()); 
		default: 
			return shared_ptr<Pizza>(new PepperoniPizza()); 
		} 
	} 
};