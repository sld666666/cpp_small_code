/** 
* @file         GPSPosition.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-10-24
*/
#pragma once
#include <fstream>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


using namespace boost;

class GPSPosition
{
public: 
	GPSPosition(){};
	GPSPosition(int d, int m,  float s)
		: degrees_(d)
		, minutes_(m)
		, seconds_(s)
	{

	}

	void print()
	{
		std::cout << degrees_ << ", "<<minutes_ <<"," <<seconds_ << std::endl;
	}
private:
	friend class serialization::access;

	template<typename T>
	void serialize(T& ar, const unsigned int version)
	{
		ar & degrees_;
		ar & minutes_;
		ar & seconds_;
	}

private:
	int	degrees_;
	int minutes_;
	float seconds_;


};

struct  Postion
{
	int x;
	int y;
	Postion(int i, int j)
		: x(i)
		, y(j)
	{

	}
};

namespace boost {
	namespace serialization {

		template<class Archive>
		void serialize(Archive & ar, Postion& g, const unsigned int version)
		{
			ar & g.x;
			ar & g.y;
		}

	} // namespace serialization
} // namespace boost


void serializefun()
{
	const GPSPosition pos(34,35, 24.345f);

	{
		std::ofstream ofs("filename");
		archive::text_oarchive oa(ofs);
		oa << pos;
	}

	GPSPosition newPos;
	{
		std::ifstream ifs("filename");
		
		archive::text_iarchive ia(ifs);

		ia >> newPos;
		
		newPos.print();
	}

	Postion pos3(10, 100);
	{
		std::ofstream ofs("filename1");
		archive::text_oarchive oa(ofs);
		oa << pos3;
	}

	Postion pos4(0, 0);
	{
		std::ifstream ifs("filename1");

		archive::text_iarchive ia(ifs);
		ia >> pos4;

		std::cout << pos4.x << ","<< pos4.y<<std::endl;
	}

}