#pragma once

#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template <typename ParserIterator>
bool parseNumbers(ParserIterator first, ParserIterator last)
{

	bool rtn = qi::phrase_parse( first
								, last
								, qi::double_>>*(','>>qi::double_)
								, ascii::space);
	rtn = (first == last);

	return rtn;
}

void testParseNumbers()
{
	string input = "123,345";
	if (parseNumbers(input.begin(), input.end())){
		cout << "Ok" << endl;
	}else{
		cout << "failed" << endl;
	}
}