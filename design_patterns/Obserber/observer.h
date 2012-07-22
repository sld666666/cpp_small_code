#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

class Observer
{
public:
	virtual	void	update() = 0;
};

class	Subject
{
public:
	virtual void registerObserver(shared_ptr<Observer> observer) = 0;
	virtual void removeObserver(shared_ptr<Observer> observer) = 0;
	virtual void notifyObserver() = 0;
};



class WeatherData : public Subject
{
public:
	virtual void registerObserver(shared_ptr<Observer> observer)
	{
		observers_.push_back(observer);
	}

	virtual void removeObserver(shared_ptr<Observer> observer)
	{
		remove(observers_.begin(), observers_.end(), observer);
	}

	virtual void notifyObserver()
	{
		for_each(observers_.begin(), observers_.end()
			, bind(&WeatherData::notify, this, _1));
	}

private:
	void	notify(shared_ptr<Observer> observer)
	{
		observer->update();
	}

private:
	vector<shared_ptr<Observer>> observers_;
};

//й╣ож
class ConditionDispaly : public Observer
{
public:
	ConditionDispaly(shared_ptr<Subject> subject)
	{
		subject->registerObserver(shared_ptr<Observer>(this));
	}

	void update()
	{
		cout << "ConditionDispaly" <<endl;
	}
};

class StatisicsDispaly : public Observer
{
public:
	StatisicsDispaly(shared_ptr<Subject> subject)
	{
		subject->registerObserver(shared_ptr<Observer>(this));
	}

	void update()
	{
		cout << "StatisicsDispaly" <<endl;
	}
};


class ForecastDispaly : public Observer
{
public:
	ForecastDispaly(shared_ptr<Subject> subject)
	{
		subject->registerObserver(shared_ptr<Observer>(this));
	}

	void update()
	{
		cout << "ForecastDispaly" <<endl;
	}
};

