// boost_property_tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test.h"
#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>  
#include <boost/filesystem/operations.hpp>

using namespace std;
using namespace boost::property_tree;
using namespace boost;

#define foreach BOOST_FOREACH

void load(const string& fileName);
void save(const string& fileName);


int _tmain(int argc, _TCHAR* argv[])
{
	int* test_0 = Test().getTest();
	int* test_1 = Test().getTest();
	testClass test;
	int i = test.mfun(1);

	string PATH = filesystem::initial_path<filesystem::path>().string() 
		+ "/config.xml";
	//PATH = "d:\\\\tmp\\config.xml";
	load(PATH);
	save(PATH);
	load(PATH);
	return 0;
}

void load(const string& fileName)
{
	using boost::property_tree::ptree;
	ptree tree;
	
	xml_parser::read_xml(fileName, tree);

	foreach(ptree::value_type& val, tree.get_child("debug"))
	{
		cout << val.first << " , ";
		cout << val.second.data();
		cout << endl;
	}

	cout << tree.get<int>("debug.level")<<endl;
}

void save(const string& fileName)
{
	using boost::property_tree::ptree;
	ptree tree;

	xml_parser::read_xml(fileName, tree);

	tree.put("debug.filename", "sld");
	tree.put("debug.lever", 0);

	write_xml(fileName, tree);
}

