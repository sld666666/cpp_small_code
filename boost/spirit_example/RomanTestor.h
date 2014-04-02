#pragma  once

#define BOOST_TEST_MODULE romanTestor
#include <boost/test/included/unit_test.hpp>
#include <string>
#include <iostream>
#include "Roman.h"

using std::string;

BOOST_AUTO_TEST_SUITE (romanTestor)

BOOST_AUTO_TEST_CASE(test0)
{
	roman<char> roman_parser;
	string str("1234");
	unsigned result;
	bool r = qi::parse(str.begin(), str.end(), roman_parser, result);
	//cout << result < endl;
}

BOOST_AUTO_TEST_SUITE_END()