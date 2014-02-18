// visitor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class AbsEmployee;
class IVisitor{
public:
	virtual void	visit(AbsEmployee* employee) = 0;
};

class AbsEmployee
{
public:
	string	name(){return name_;}
	void	setName(const string& name){name_ = name;}

	double	salary(){return salary_;}
	void	setSalary(double salary){salary_ = salary;}

	virtual	void	accept(IVisitor* visitor)=0;

private:
	string name_;
	double salary_;
};

class CommonEmployee : public AbsEmployee
{

public:
	virtual	void	accept(IVisitor* visitor)
	{
		visitor->visit(this);
	}
};

class ManagerEmployee : public AbsEmployee
{
public:
	virtual	void	accept(IVisitor* visitor)
	{
		visitor->visit(this);
	}
};




class ITotalSalaryVisitor:public IVisitor
{
public:
	virtual double totalSalary() = 0;
};

class EmployeeTotalSalaryVisitor :public ITotalSalaryVisitor
{
public:
	virtual void	visit(AbsEmployee* employee)
	{
		employees_.push_back(employee);
	}
	virtual double	totalSalary()
	{
		double rtn(0.0);
		for (vector<AbsEmployee*>::iterator iter = employees_.begin()
			; iter != employees_.end(); ++iter)
		{
			rtn += getOnSalary(*iter);
		}

		return rtn;
	}

private:
	double getOnSalary(AbsEmployee* employee_)
	{
		return employee_?employee_->salary():0.0;
	}
private:
	vector<AbsEmployee*> 	employees_;
};


int _tmain(int argc, _TCHAR* argv[])
{

	ITotalSalaryVisitor* visitor(new EmployeeTotalSalaryVisitor());
	CommonEmployee comEmployee;
	comEmployee.setName("lacy");
	comEmployee.setSalary(10000.00);
	comEmployee.accept(visitor);
	double totalSalary = visitor->totalSalary();
	cout << totalSalary << endl;
	return 0;
}

