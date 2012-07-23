#pragma one

#include <iostream>

using namespace  std;

class ConditionDispaly
{
public:
	void update(double temp, double humidity, double pressure)
	{
		cout << "ConditionDispaly" << temp << "," << humidity << "," << pressure <<endl;
	}
};

class StatisicsDispaly
{
public:
	void update(double temp, double humidity, double pressure)
	{
		cout << "StatisicsDispaly" << temp << "," << humidity << "," << pressure <<endl;
	}
};

class ForecastDispaly
{
public:
	void update(double temp, double humidity, double pressure)
	{
		cout << "ForecastDispaly" << temp << "," << humidity << "," << pressure <<endl;
	}
};

class WeatherData
{
public:
	void meassurmentsChanged()
	{
		double temperature = getTemplate();
		double humidity = getHumidity();
		double preessure = getPreessure();

		conditionDispaly.update(temperature,humidity, preessure);
		statisicsDispaly.update(temperature,humidity, preessure);
		forecastDispaly.update(temperature,humidity, preessure);

	}

	 

private:
	double  getTemplate()
	{
		return 10.1;
	}

	double getHumidity()
	{
		return 20.1;
	}

	double getPreessure()
	{
		return 30.1;
	}


private:
	ConditionDispaly	conditionDispaly;
	StatisicsDispaly	statisicsDispaly;
	ForecastDispaly		forecastDispaly;
};