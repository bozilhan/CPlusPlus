/******************************************************************************
 *
 * (C) 2015 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File :
 *          Smiley
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
 *         Smiley.cpp
 *
 * Notes :
 *          XXX
 *
 *****************************************************************************/

#include "Smiley.h"

using namespace CH;

Smiley::Smiley() :
		m_pMouth( nullptr )
{
}

Smiley::~Smiley()
{
}

Smiley::Smiley( const Point& point, const uint8_t& radius ) :
		Circle( point, radius ),
		m_pMouth( nullptr )
{
}

void Smiley::draw() const
{
	Circle::draw();

	for ( auto p : m_Eyes )
	{
		p->draw();
	}

	m_pMouth->draw();
}

void Smiley::addEye( Shape* pShape )
{
	m_Eyes.push_back( pShape );
}

void Smiley::setMouth( Shape* pMouth )
{
	m_pMouth = pMouth;
}
