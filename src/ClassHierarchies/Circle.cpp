/******************************************************************************
 *
 * (C) 2015 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File :
 *          Circle
 *
 * Purpose :
 *           XXX
 *
 * History :
 *
 * Date          Author                Changes
 * -----------   -------------------   --------------------------
 * 12.05.2015    bozilhan                Initial Release
 *
 * CSU ID :
 *          10-033-I-MARLIN
 *
 * Class :
 *         Circle.cpp
 *
 * Notes :
 *          XXX
 *
 *****************************************************************************/

#include "Circle.h"

using namespace CH;

Circle::Circle() :
		m_Point(),
		m_Radius( 0 )
{
}

Circle::Circle( const Point& point, const uint8_t& radius ) :
		m_Point( point ),
		m_Radius( radius )
{
}

Circle::~Circle()
{
}

const Point& Circle::center() const
{
	return m_Point;
}

void Circle::move( Point& to )
{
	m_Point = to;
}

void Circle::rotate( const uint8_t& angle )
{

}

void Circle::draw() const
{

}

void Circle::setRadius( const uint8_t& radius )
{
	m_Radius = radius;
}
