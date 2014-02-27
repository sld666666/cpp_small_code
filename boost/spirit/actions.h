#pragma once
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>

using namespace std;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
using namespace boost;
using namespace boost::lambda;

void print(int i)
{
	cout << i << endl;
}

struct Writer 
{
	void print(int i) const
	{
		cout << i << endl;
	}
};

struct PrintAction
{
	void operator()(int const&i, qi::unused_type, qi::unused_type)const
	{
		cout << i << endl;
	}
};



void parserAction()
{
	string str = "{43}";
	qi::parse(str.begin(), str.end(), '{'>>qi::int_[&print]>>'}');

	qi::parse(str.begin(), str.end(), '{'>>qi::int_[PrintAction()]>>'}');

 	Writer writer;
 	qi::parse(str.begin(), str.end(), '{'>> qi::int_[bind(&Writer::print,&writer, boost::lambda::_1)]>>'}');

	qi::parse(str.begin(),  str.end(), '{'>> qi::int_[cout << boost::lambda::_1 << '\n'] >> '}');
}
