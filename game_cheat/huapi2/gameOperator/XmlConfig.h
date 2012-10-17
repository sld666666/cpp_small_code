#pragma once
#include "isingleton.h"

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>  
#include <boost/any.hpp>

using namespace std;
using namespace boost::property_tree;
using boost::property_tree::ptree;

#define foreach BOOST_FOREACH

class XmlConfig : public ISingleton<XmlConfig>
{
public:
	~XmlConfig();

	void	init();

	template<typename T>
	long getValue(const string& key)
	{
		return tree_.get<long>(key);
	}

	string getValue(const string& key)
	{
		return tree_.get<string>(key);
	}

protected:
	XmlConfig();
	friend class ISingleton<XmlConfig>;

private:
	void load(const string& fileName);

private:
	ptree tree_;
};
