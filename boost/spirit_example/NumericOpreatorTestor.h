#ifndef NUMERICOPREATORTESTOR_H
#define NUMERICOPREATORTESTOR_H
#define BOOST_TEST_MODULE numericopreatortestor
#include <boost/test/included/unit_test.hpp>
#include "NumericOpreator.h"

BOOST_AUTO_TEST_SUITE (numericopreatortestor)

BOOST_AUTO_TEST_CASE(test0)
{
	NumericOpreator opr("123*223");
	opr.testInGramar();
}

BOOST_AUTO_TEST_SUITE_END()

#endif // NUMERICOPREATORTESTOR_H
