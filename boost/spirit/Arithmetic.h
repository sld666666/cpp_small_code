#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/spirit.hpp>
#include <boost/spirit/phoenix.hpp>
#include <vector>

using namespace std;
using namespace boost::spirit;
using namespace phoenix;
void calc();
void testPhoenix();

void arithmetic()
{
	rule<phrase_scanner_t> factor, term, exp;
	factor = real_p | ('(' >> exp >> ')');
	term   = factor >> *(('*' >> factor) | ('/' >> factor));
	exp    = term >> *(('+' >> term) | ('-' >> term));

	const char *szExp = "1 + (2 * (3 / (4 + 5)))";
	parse_info<> r = parse( szExp , exp, space_p);
	cout << "parsed " << (r.full?"successful":"failed") << endl;
	//testPhoenix();
	calc();
}

void testPhoenix()
{
	vector <int>vec(10);
	int i(0);
	for_each(vec.begin(), vec.end(), arg1 = var(i)++);
	for_each(vec.begin(), vec.end(), cout<<arg1<<endl);
}

void calc()
{
	//为rule准备一个val变量，类型为double
	//准确地说：是一个phoenix类(这里的member1)，它和其它phoenix类组成lambda表达式，在lambda中可以把它看成是一个double。      
	struct calc_closure : boost::spirit::closure<calc_closure, double>
	{
		member1 val;
	};
	//定义ContextT策略为calc_closure::context_t
	rule<phrase_scanner_t, calc_closure::context_t> factor, term, exp;
	//直接使用phoenix的lambda表达式作为Actor
	factor = real_p[factor.val = arg1] | ('(' >> exp[factor.val = arg1] >> ')');
	term   = factor[term.val = arg1] >> *(('*' >> factor[term.val *= arg1]) | ('/' >> factor[term.val /= arg1]));
	exp    = term[exp.val = arg1] >> *(('+' >> term[exp.val += arg1]) | ('-' >> term[exp.val -= arg1]));
	const char *szExp = "1 + (2 * (3 / (4 + 5)))";
	double result;
	parse_info<> r = parse( szExp , exp[assign_a(result)], space_p);
	cout << szExp;
	if(r.full)
	{
		//成功，得到结果
		cout << " = " << result << endl;
	}
	else
	{
		//失败，显示错误位置
		cout << endl << string(r.stop - szExp, ' ') << '^' << endl;
	}
}