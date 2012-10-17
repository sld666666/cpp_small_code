#include "StdAfx.h"
#include "XmlConfig.h"

XmlConfig::XmlConfig()
{
}

XmlConfig::~XmlConfig()
{
}

void XmlConfig::init()
{
	const string fileName = "d:\\\\tmp\\config.xml";
	load(fileName);

}

void XmlConfig::load(const string& fileName)
{
	xml_parser::read_xml(fileName, tree_);
	string test = tree_.get<string>("game.caption");
	int i;

}

