// dp_command.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>

using namespace std;

#define foreach BOOST_FOREACH
// 烤肉师傅
class RoastCook
{
public:
	void	makeMutton()	
	{
		cout << "烤羊肉" << endl;
	}


	void	makeChickWing()
	{
		cout << "烤鸡翅膀" <<endl;
	}

};


// 抽象命令类
class Command
{
public:
	Command(RoastCook* tmp)
		: receiver(tmp)
	{
		
	}

virtual void execut() = 0;
protected:
	RoastCook* receiver;
};

// 烤羊肉命令

class MakeMuttonCmd : public Command

{

public:

	MakeMuttonCmd(RoastCook* tmp) : Command(tmp) {}

	virtual void execut() { receiver->makeMutton(); }

};

// 烤鸡翅膀命令

class MakeChickenWingCmd : public Command

{

public:

	MakeChickenWingCmd(RoastCook* tmp) : Command(tmp) {}

	virtual void execut() { receiver->makeChickWing(); }

};


// 服务员类

class Waiter

{

public:

	void appendCommand(Command* cmd)
	{
		commandList_.push_back(cmd);
	}

	// 通知执行

	void invoke()
	{
		foreach(Command* cmd, commandList_)
		{
			cmd->execut();
		}
	}

protected:
	vector<Command*> commandList_;

};




int _tmain(int argc, _TCHAR* argv[])
{
	RoastCook* cook = new RoastCook();

	Command* cmd1 = new MakeMuttonCmd(cook);

	Command* cmd2 = new MakeChickenWingCmd(cook);

	Waiter* girl = new Waiter();

	// 点菜

	girl->appendCommand(cmd1);

	girl->appendCommand(cmd2);

	// 服务员通知

	girl->invoke();

	return 0;
}

