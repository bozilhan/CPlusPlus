#include "Location.h"

using namespace INT;

Location::Location() :
	m_X( 0 ),
	m_Y( 0 )
{
}

uint8_t Location::getX() const
{
	return m_X;
}

void Location::setX( const uint8_t& x )
{
	m_X = x;
}

uint8_t Location::getY() const
{
	return m_Y;
}

void Location::setY( const uint8_t& y )
{
	m_Y = y;
}

void Location::setXY( const uint8_t& x, const uint8_t& y )
{
	m_X = x;
	m_Y = y;
}
