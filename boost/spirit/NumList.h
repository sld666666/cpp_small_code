#pragma once
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/lambda/lambda.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace client
{
	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;
	namespace phoenix = boost::phoenix;

	///////////////////////////////////////////////////////////////////////////////
	//  Our number list compiler
	///////////////////////////////////////////////////////////////////////////////
	//[tutorial_numlist3
	template <typename Iterator>
	bool parse_numbers(Iterator first, Iterator last, std::vector<double>& v)
	{
		using qi::double_;
		using qi::phrase_parse;
		using qi::_1;
		using ascii::space;
		using phoenix::push_back;

		bool r = phrase_parse(
			 first
			, last
			,(double_[push_back(phoenix::ref(v), _1)] % ',')
			, space);

		if (first != last) // fail if we did not get a full match
			return false;
		return r;
	}
}

void testNumList()
{
	std::vector<double> vec;
	std::string str("1.23,2.23,3.67,4.98");
	client::parse_numbers(str.begin(), str.end(), vec);
	std::for_each(vec.begin(), vec.end(), std::cout<< boost::lambda::_1<<boost::lambda::constant(" "));
}