// adapter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

class IDuck
{
public:
	virtual void quack()=0;

	virtual void fly()=0;
};

class MallarDuck : public IDuck
{
	public:
	void quack()
	{
		cout << "duck quack" <<endl;
	}

	void fly()
	{
		cout << "duck fly" <<endl;
	}
};

class ITurkey
{
	public:
	virtual void gobble() = 0;
	virtual void walk() = 0;
};

class WildTurkey : public ITurkey
{
public:
	void gobble()
	{
		cout << "WildTurkey gobble" <<endl;
	}

	void walk()
	{
		cout << "WildTurkey walk" <<endl;
	}
};

class TurkeyAdapter : public IDuck
{
public:
	TurkeyAdapter(shared_ptr<ITurkey> turkey)
		:turkey_(turkey)
	{
		
	}

	void quack()
	{
		turkey_->gobble();
	}

	void fly()
	{
		turkey_->walk();
	}

private:
	shared_ptr<ITurkey> turkey_;
};


int _tmain(int argc, _TCHAR* argv[])
{
	shared_ptr<ITurkey> wildTurkey(new WildTurkey());
	shared_ptr<IDuck> mallarDuck(new MallarDuck());

	shared_ptr<IDuck> turkeyAdapter(new TurkeyAdapter(wildTurkey));

	mallarDuck->fly();
	mallarDuck->quack();

	turkeyAdapter->fly();
	turkeyAdapter->quack();
	return 0;
}

