#pragma once

class FactoryMethod
{
public:
	FactoryMethod(){}
	virtual ~FactoryMethod(){}

	virtual shared_ptr<Pizza> MakePizza()= 0;

};

class CheeseFactoryMethod : public FactoryMethod
{
	public:
		CheeseFactoryMethod(){}
		~CheeseFactoryMethod(){}

	shared_ptr<Pizza>MakePizza()
	{
		return shared_ptr<Pizza>(new CheesePizza());
	}
};