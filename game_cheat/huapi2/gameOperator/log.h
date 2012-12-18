#pragma once
#include "isingleton.h"
#include <string>
#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/configurator.h>
#include <log4cplus/consoleappender.h>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;


class Log : public ISingleton<Log>
{
public:
	~Log(){};
	
	void  debugMsg(const string& tag, int val){
		LOG4CPLUS_DEBUG(logger_, tag.c_str()<<"		"<< val );
	}

	void  debugMsg(const string& tag){
		LOG4CPLUS_WARN(logger_, tag.c_str());
	}
	

protected:
	Log():logger_(Logger::getInstance(LOG4CPLUS_TEXT("debuglogger")))
	{
		PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("d:\\tmp\\log4cplus.properties"));
	}
	friend class ISingleton<Log>;

private:
	Logger logger_;
	
};
