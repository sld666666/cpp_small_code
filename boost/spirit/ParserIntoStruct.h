#pragma once
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/>

#include <string>
using std::string;

namespace client
{
	struct employee{
		int age;
		string surname;
		string forename;
		double salary;
	};

	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;

}

BOOST_FUSION_ADAPT_STRUCT(
  client::employee,
  (int, age)
  (string, surname)
  (string, forename)
  (double, salary)
)

namespace client
{
	template <typename Iterator>
	struct employee_parser : qi::grammar<Iterator, employee(), ascii::space_type>
	{
		employee_parser() : employee_parser::base_type(start)
		{
			using qi::int_;
			using qi::lit;
			using qi::double_;
			using qi::lexeme;
			using ascii::char_;

			quoted_string %= lexeme['"' >> +(char_ - '"') >> '"'];

			start %=
				lit("employee")
				>> '{'
				>>  int_ >> ','
				>>  quoted_string >> ','
				>>  quoted_string >> ','
				>>  double_
				>>  '}'
				;
		}

		qi::rule<Iterator, std::string(), ascii::space_type> quoted_string;
		qi::rule<Iterator, employee(), ascii::space_type> start;
	};
}