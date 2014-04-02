#include "NumericOpreator.h"
#include <algorithm>
#include <boost/lambda/lambda.hpp>




NumericOpreator::NumericOpreator(const string& input)
{
    this->input_ = input;
}

int NumericOpreator::toNumlist()
{
	//testLambda();
    int result(0);
    bool rtn = qi::phrase_parse(this->input_.begin()
                         , this->input_.end()
						 , qi::int_[result += boost::lambda::_1]>>*("+">>qi::int_[result += boost::lambda::_1])
                         , ascii::space);
    return result;
}

void NumericOpreator::testInGramar()
{
	typedef NumberGramar<std::string::const_iterator> NumberGramar;
	NumberGramar numberGramar;

	int result(0);
	bool rtn = qi::phrase_parse(this->input_.begin()
		, this->input_.end()
		, (numberGramar)
		, ascii::space);

	std::cout <<result<<std::endl;
}

void NumericOpreator::testLambda()
{
	vector<int> vec;
	for(int i = 0; i < 10; ++i){
		vec.push_back(i);
	}

	int result(0);
	std::for_each(vec.begin()
		, vec.end()
		, result += boost::lambda::_1);
	std::cout << result << std::endl;
}

