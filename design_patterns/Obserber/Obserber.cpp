// Obserber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "normal.h"
#include "observer.h"

int _tmain(int argc, _TCHAR* argv[])
{
// 	WeatherData weathdata;
// 	weathdata.meassurmentsChanged();

	shared_ptr<WeatherData> weatherData(new WeatherData());
	shared_ptr<ConditionDispaly> conditionDispaly(new ConditionDispaly(weatherData));
	shared_ptr<StatisicsDispaly> statisDispaly(new StatisicsDispaly(weatherData));
	shared_ptr<ForecastDispaly> forecastDispaly(new ForecastDispaly(weatherData));
	weatherData->notifyObserver();

	return 0;
}

