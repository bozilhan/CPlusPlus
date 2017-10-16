/******************************************************************************
 *
 * (C) 2015 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File :
 *          Point
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
 *         Point.cpp
 *
 * Notes :
 *          XXX
 *
 *****************************************************************************/

#include "Point.h"

using namespace CH;

Point::Point() :
		m_X( 0 ),
		m_Y( 0 )
{
}

Point::~Point()
{
}

uint8_t Point::getX() const
{
	return m_X;
}

void Point::setX( const uint8_t& x )
{
	m_X = x;
}

uint8_t Point::getY() const
{
	return m_Y;
}

void Point::setY( const uint8_t& y )
{
	m_Y = y;
}

void Point::setXY( const uint8_t& x, const uint8_t& y )
{
	m_X = x;
	m_Y = y;
}
