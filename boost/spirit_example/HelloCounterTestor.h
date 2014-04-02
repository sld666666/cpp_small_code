#ifndef HELLOCOUNTERTESTOR_H
#define HELLOCOUNTERTESTOR_H

#define BOOST_TEST_MODULE hellocountertestor
#include <boost/test/included/unit_test.hpp>
#include <string>
#include "HelloCounter.h"

using std::string;

BOOST_AUTO_TEST_SUITE (hellocountertestor)

BOOST_AUTO_TEST_CASE(test0)
{
    const string input = "This Hello World program using Spirit counts the number of\
                    Hello World occurrences in the input";
    int counts = doCount(input.begin(), input.end());
    BOOST_CHECK(counts == 2);
}

BOOST_AUTO_TEST_SUITE_END()
#endif // HELLOCOUNTERTESTOR_H
