// State.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class IContext;

class AbsLiftState
{
public:
	void	setContext(IContext* context)
	{
		context_ = context;
	}

	virtual	void open();
	virtual void close();
	virtual void run();
	virtual void stop();
protected:
	IContext* context_;
};


class OpenState : public AbsLiftState
{
public:
	virtual	void open()
	{
		cout <<"door open..."<<endl;
	}
	virtual void close()
	{
		AbsLiftState::context_->setLiftState(context_->CloseLifeState_)
		AbsLiftState::context_->getLiftState()->close();
	}

	virtual void run(){}
	virtual void stop(){}
};

class CloseState : public AbsLiftState
{
public:
	virtual	void open()
	{
		AbsLiftState::context_->setLiftState(context_->OpenLiftState_)
		AbsLiftState::context_->getLiftState()->open();
	}
	virtual void close()
	{
		cout <<"door close..."<<endl;
	}
	virtual void run()
	{
		
	}
	virtual void stop()
	{

	}
};

class IContext
{
public:
	virtual void	setLiftState(AbsLiftState* liftState) = 0;
	virtual AbsLiftState*	getLiftState()=0;
};

class Context : public IContext
{
public:
	AbsLiftState*	OpenLiftState_;
	AbsLiftState*	CloseLifeState_;

public:
	Context()
		: OpenLiftState_(new OpenState())
		, CloseLifeState_(new CloseState()){}

	void	setLiftState(AbsLiftState* liftState)
	{
		this->liftState_ = liftState;
	}

	AbsLiftState*	getLiftState()
	{
		return liftState_;
	}

	void open(){liftState_->open();}
	void close(){liftState_->close();}
	void run(){liftState_->run();}
	void stop(){liftState_->stop();}
private:
	AbsLiftState*	liftState_;
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

