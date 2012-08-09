/** 
* @file         command.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         9:8:2012  
*/

#pragma once

#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <algorithm>

using namespace std;
using namespace boost;

class ICommand
{
public:
	ICommand(){}
	~ICommand(){}

	virtual void execute() = 0;

};

class LightOnCommand : public ICommand
{

public:
	LightOnCommand(){}
	~LightOnCommand(){}

	virtual void execute()
	{
		cout<< "LightOnCommand"<<endl;
	}
};

class LightOffCommand : public ICommand
{
public:
	LightOffCommand(){}
	~LightOffCommand(){}

	virtual void execute()
	{
		cout<< "LightOffCommand"<<endl;
	}
};

class CommandManager
{
public:
	CommandManager(){}
	~CommandManager(){}

	void addCommand(shared_ptr<ICommand>cmd)
	{
		commands_.push_back(cmd);
	}

	void execute()
	{
		for_each(commands_.begin(), commands_.end()
			, boost::bind(&ICommand::execute,_1));
	}

private:
	vector<shared_ptr<ICommand>> commands_;
};