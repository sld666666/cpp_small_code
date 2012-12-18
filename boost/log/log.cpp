log.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/configurator.h>
#include <log4cplus/consoleappender.h>

using namespace log4cplus;
using namespace log4cplus::helpers;



void printDebug()
{
	/* step 1: Instantiate an appender object */   
	//LOG4CPLUS_TEXT("Test.log")
// 	SharedAppenderPtr appender(new ConsoleAppender());    
// 	appender->setName(LOG4CPLUS_TEXT("file_log_test"));    

	/* step 4: Instantiate a logger object */  

	 Logger root = Logger::getRoot();

	PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("d:\\tmp\\log4cplus.properties"));
	Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("debuglogger"));
	LOG4CPLUS_WARN(root, "Starting test loop....");

		
	//= Logger::getInstance(LOG4CPLUS_TEXT("test.subtestof_filelog"));    

	/* step 5: Attach the appender object to the logger  */   
 	//logger.addAppender(appender);    

	/* log activity */    
       
		LOG4CPLUS_DEBUG(logger, "Entering loop #" << 0 << "End line #");
	
}

int _tmain(int argc, _TCHAR* argv[])
{

	printDebug();
	return 0;
}
