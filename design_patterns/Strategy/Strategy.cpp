// Strategy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <boost/shared_ptr.hpp>
using namespace std;
using boost::shared_ptr;
class IStrategy{
public:
	virtual void done() = 0;
};

class BackDoor : public IStrategy{
public:
	virtual void  done(){
		cout << "BackDoor" << endl;
	}
};

class BlockEnemy : public IStrategy{
public:
	virtual void done(){
		cout << "BlockEnemy" <<endl;
	}
};


class StrategyContainer{
public:
	StrategyContainer(shared_ptr<IStrategy> stragety){
		this->stragety_ = stragety;
	}

	void done()
	{
		if (this->stragety_.get()){
			this->stragety_->done();
		}
	}

private:
	shared_ptr<IStrategy> stragety_;

};

int _tmain(int argc, _TCHAR* argv[])
{
	shared_ptr<BackDoor> backDoor(new BackDoor());
	shared_ptr<BlockEnemy>blockEnemy(new BlockEnemy());

	shared_ptr<StrategyContainer>strategyContainer(new StrategyContainer(backDoor));
	strategyContainer->done();

	strategyContainer = shared_ptr<StrategyContainer>(new StrategyContainer(blockEnemy));
	strategyContainer->done();
	return 0;
}

