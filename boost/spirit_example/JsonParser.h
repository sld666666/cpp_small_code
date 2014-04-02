#pragma once
#include <iostream>
#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/any.hpp>
#include <map>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template<typename Iterator>
struct json_grammar : qi::grammar<Iterator, boost::any(), ascii::space_type>
{
	json_grammar()
		: json_grammar::base_type(element)
	{
		number %= qi::double_;
		array %= qi::eps >> '[' >> element % ',' >> ']';
		string %= qi::lexeme['\"' >> +(ascii::char_ - '\"') >> '"'];
		key_value %= string >> ':' >> element;
		object %= qi::eps >> '{' >> key_value % ',' >> '}';
		element %= array | object | string | number;
	}

	qi::rule<Iterator, std::vector<boost::any>(), ascii::space_type> array;
	qi::rule<Iterator, std::pair<std::string, boost::any>(), ascii::space_type> key_value;
	qi::rule<Iterator, std::map<std::string, boost::any>(), ascii::space_type> object;
	qi::rule<Iterator, std::string(), ascii::space_type> string;
	qi::rule<Iterator, double(), ascii::space_type> number;
	qi::rule<Iterator, boost::any(), ascii::space_type> element;
};

void parserToMap()
{
	typedef json_grammar<std::string::const_iterator> Parser;
	Parser p;
	const std::string str = "({\"abc\":\"def\"})";
	boost::any result;
	if(qi::phrase_parse(str.begin(), str.end(), p, ascii::space, result))
	{
		std::cout << "format ok" << std::endl;
		std::map<std::string, boost::any> p = boost::any_cast<std::map<std::string, boost::any>>(result);
		std::cout << boost::any_cast<std::string>(p["abc"]) << std::endl;
	}
}