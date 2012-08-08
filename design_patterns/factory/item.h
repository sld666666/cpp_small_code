/** 
* @file         item.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         8:8:2012  
*/

#pragma once

#include <boost/shared_ptr.hpp>
#include <iostream>
using namespace boost;
using namespace std;

class Pizza 
{ 
public: 
	Pizza(){}; 
	virtual ~Pizza(){};

	virtual void MakePizza() = 0; 
};

class CheesePizza : public Pizza 
{ 
public: 
	CheesePizza(){}; 
	~CheesePizza(){};

	void MakePizza() 
	{ 
		cout << "make cheese pizza" <<endl; 
	} 
};

class GreekPizza : public Pizza 
{ 
public: 
	GreekPizza(){}; 
	~GreekPizza(){};

	void MakePizza() 
	{ 
		cout << "make greek pizza" <<endl; 
	}

};

class PepperoniPizza : public Pizza 
{ 
public: 
	PepperoniPizza(){}; 
	~PepperoniPizza(){};

	void MakePizza() 
	{ 
		cout << "make peperoni pizza" <<endl; 
	}

};

enum PIZZA_TYPE 
{ 
	PIZZA_TYPE_CHEESE = 0, 
	PIZZA_TYPE_GREEK, 
	PIZZA_TYPE_PEPPERONI 
};

class Milk 
{ 
public: 
	Milk(){}; 
	virtual ~Milk(){};

	virtual void MakeMilk() = 0; 
};

class Yogurt : public Milk
{
	void MakeMilk(){cout << "make Yogurt" << endl;}
};