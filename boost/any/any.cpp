// any.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost/any.hpp>
#include <boost/bind.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

typedef std::vector<boost::any> ListAny;
using std::string;
using namespace boost;
class Container{
public:
	void appendInt(int val){
		boost::any toAppend(val);
		datas_.push_back(toAppend);
	}

	void appendDouble(double val){
		datas_.push_back(val);
	}

	void appendString(string val){
		datas_.push_back(val);
	}

	bool isEmpty(const boost::any & operand){
		return operand.empty();
	}

	bool isInt(const boost::any & operand){
		return operand.type() == typeid(int);
	}

	bool isDouble(const boost::any& operand){
		try{
			any_cast<double>(operand);
			return true;
		}catch(boost::bad_any_cast&){
			return false;
		}
	}

	void count_all(){
		std::cout << std::count_if(datas_.begin(), datas_.end()
			, bind(&Container::isInt, this, _1)) << std::endl;

		std::cout << std::count_if(datas_.begin(), datas_.end()
			, bind(&Container::isDouble, this, _1)) << std::endl;
	}

	ListAny	datas_;
};



void testUserDefine()
{
	struct UD{
		int a;
		double b;
		UD() : a(1), b(2){}
	};
	UD ud;
	boost::any test(ud);
	bool isOK = (test.type() == typeid(UD) );
}
int _tmain(int argc, _TCHAR* argv[])
{
	testUserDefine();
	Container container;
	container.appendInt(1);
	container.appendDouble(2.1);
	container.appendString("3");
	double test = any_cast<double>(container.datas_[1]);
	std::cout << test << std::endl;
	container.count_all();
	return 0;
}

