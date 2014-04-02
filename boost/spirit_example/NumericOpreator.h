#ifndef NUMERICOPREATOR_H
#define NUMERICOPREATOR_H
#include <string>
#include <vector>
#include <iostream>
#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
using std::string;
using std::vector;

template <typename ITERATOR>
struct NumberGramar : public qi::grammar<ITERATOR, unsigned>
{
	NumberGramar():base_type(start)
	{
		start = qi::int_>>*('+'>>qi::int_);
	}

	qi::rule<ITERATOR, unsigned> start;
};

class NumericOpreator
{

public:
    NumericOpreator(const string& input);

	void testInGramar();
    int  toNumlist();
private:
	void testLambda();
private:
    string input_;
};


#endif // NUMERICOPREATOR_H
