#pragma once

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <iostream>
#include <string>

namespace client
{

	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;
	namespace phoenix = boost::phoenix;

	using qi::double_;
	using qi::_1;
	using ascii::space;
	using phoenix::ref;

	template<typename Iter>
	bool adder(Iter first, Iter last, double& n)
	{
		bool rtn = qi::phrase_parse(
			first
			, last
			, (double_[ref(n) = _1] >> *(',' >> double_[ref(n) += _1]))
			, space);

		return rtn;
	}

}

void testSum()
{
	std::string input="123.34,1234";
	double n;
	bool rtn = client::adder(input.begin(), input.end(), n);
	std::cout << n << std::endl;
}