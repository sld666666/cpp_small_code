#pragma once

#include <boost/spirit/include/qi.hpp>
#include <boost/lambda/lambda.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template<typename ITERAOR>
bool parse_complex(ITERAOR first
				   , ITERAOR, last
				   , std::complex<double>& output)
{
	
	bool rtn(false);
	double rN = 0.0, iN=0.0;
	rtn = qi::phrase_parse(first
							, last
							, ('('>>qi::double_')')
							, ascii::space)
	return rtn;
}