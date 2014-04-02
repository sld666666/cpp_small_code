#pragma once

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <iostream>
#include <string>

namespace client
{
	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;

	///////////////////////////////////////////////////////////////////////////////
	//  Parse roman hundreds (100..900) numerals using the symbol table.
	//  Notice that the data associated with each slot is the parser's attribute
	//  (which is passed to attached semantic actions).
	///////////////////////////////////////////////////////////////////////////////
	//[tutorial_roman_hundreds
	struct hundreds_ : qi::symbols<char, unsigned>
	{
		hundreds_()
		{
			add
				("C"    , 100)
				("CC"   , 200)
				("CCC"  , 300)
				("CD"   , 400)
				("D"    , 500)
				("DC"   , 600)
				("DCC"  , 700)
				("DCCC" , 800)
				("CM"   , 900)
				;
		}

	} hundreds;
	//]

	///////////////////////////////////////////////////////////////////////////////
	//  Parse roman tens (10..90) numerals using the symbol table.
	///////////////////////////////////////////////////////////////////////////////
	//[tutorial_roman_tens
	struct tens_ : qi::symbols<char, unsigned>
	{
		tens_()
		{
			add
				("X"    , 10)
				("XX"   , 20)
				("XXX"  , 30)
				("XL"   , 40)
				("L"    , 50)
				("LX"   , 60)
				("LXX"  , 70)
				("LXXX" , 80)
				("XC"   , 90)
				;
		}

	} tens;
	//]

	///////////////////////////////////////////////////////////////////////////////
	//  Parse roman ones (1..9) numerals using the symbol table.
	///////////////////////////////////////////////////////////////////////////////
	//[tutorial_roman_ones
	struct ones_ : qi::symbols<char, unsigned>
	{
		ones_()
		{
			add
				("I"    , 1)
				("II"   , 2)
				("III"  , 3)
				("IV"   , 4)
				("V"    , 5)
				("VI"   , 6)
				("VII"  , 7)
				("VIII" , 8)
				("IX"   , 9)
				;
		}

	} ones;
	//]

	///////////////////////////////////////////////////////////////////////////////
	//  roman (numerals) grammar
	//
	//      Note the use of the || operator. The expression
	//      a || b reads match a or b and in sequence. Try
	//      defining the roman numerals grammar in YACC or
	//      PCCTS. Spirit rules! :-)
	///////////////////////////////////////////////////////////////////////////////
	//[tutorial_roman_grammar
	template <typename Iterator>
	struct roman : qi::grammar<Iterator, unsigned()>
	{
		roman() : roman::base_type(start)
		{
			using qi::eps;
			using qi::lit;
			using qi::_val;
			using qi::_1;
			using ascii::char_;

			start = eps     [_val = 0] >>
				( +lit('M') [_val += 1000]
			||  hundreds    [_val += _1]
			||  tens        [_val += _1]
			||  ones        [_val += _1]
			)
				;
		}

		qi::rule<Iterator, unsigned()> start;
	};
	//]
}

void parseRoman()
{
	typedef std::string::const_iterator iterator_type;
	typedef client::roman<iterator_type> roman;

	std::string input("1");
	unsigned result;
	roman roman_parser;
	bool r = parse(input.begin(), input.end(), roman_parser, result);
	std::cout << result <<std::endl;
}