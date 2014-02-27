//#define  BOOST_SPIRIT_NO_REGEX_LIB
#include <iostream>
#include <boost/spirit/actor.hpp>
#include <boost/spirit.hpp>
#include <boost/regex.h>

using namespace boost::spirit;
using namespace std;

const string input = "This Hello World program using Spirit counts the number of\
					Hello World occurrences in the input";

void testFun_01()
{
	int count = 0;
	parse(input.c_str()
		, *(str_p("Hello World") [ increment_a(count) ]|anychar_p));

	cout << count << endl;
}

