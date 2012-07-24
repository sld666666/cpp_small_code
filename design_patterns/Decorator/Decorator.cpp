// Decorator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

class Beverage
{
public:
	virtual double cost()=0;
	
	virtual string description()=0;
};

#pragma region conffe
class HouseBlend : public Beverage
{
public:
	virtual double cost(){ return 10.1;}

	virtual string description(){return "HouseBlend ";}
};

class DarkRoast : public Beverage
{
public:
	virtual double cost(){return 20.1;}

	virtual string description(){return "DarkRoast ";}
};
#pragma endregion conffe

#pragma region Decorator


class CondlmentDecorator : public Beverage
{
public:
	CondlmentDecorator(shared_ptr<Beverage> beverage)
		:beverage_(beverage)
	{

	}


	virtual double cost()=0;

	virtual string description()=0;

protected:
	shared_ptr<Beverage> beverage_;
};

class Milk : public CondlmentDecorator
{
public:
	Milk(shared_ptr<Beverage> beverage)
		: CondlmentDecorator(beverage)
	{

	}

	virtual double cost(){return beverage_->cost() + 1;}

	virtual string description(){return beverage_->description()+ "Milk";}
};

class Mocha : public CondlmentDecorator
{
public:
	Mocha(shared_ptr<Beverage> beverage)
		: CondlmentDecorator(beverage)
	{

	}

	virtual double cost(){return beverage_->cost() + 2;}

	virtual string description(){return beverage_->description() + "Mocha";}
};



#pragma endregion Decorator


int _tmain(int argc, _TCHAR* argv[])
{
	shared_ptr<Beverage> beverage1 (new HouseBlend());
	beverage1 = shared_ptr<Beverage>(new Milk(beverage1));
	beverage1 = shared_ptr<Beverage>(new Mocha(beverage1));
	cout << beverage1->cost() << beverage1->description()<<endl;

	shared_ptr<Beverage> beverage2 (new DarkRoast());
	beverage2 = shared_ptr<Beverage>(new Milk(beverage1));
	beverage2 = shared_ptr<Beverage>(new Mocha(beverage1));
	cout << beverage2->cost() << beverage2->description();

	return 0;
}

