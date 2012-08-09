// command.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "command.h"


int _tmain(int argc, _TCHAR* argv[])
{
	shared_ptr<LightOnCommand> lightOncmd(new LightOnCommand());
	shared_ptr<LightOffCommand> lightOffcmd(new LightOffCommand());

	CommandManager cmdManager;
	cmdManager.addCommand(lightOncmd);
	cmdManager.addCommand(lightOffcmd);
	cmdManager.execute();
	return 0;
}

