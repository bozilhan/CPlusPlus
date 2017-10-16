/******************************************************************************
 *
 * (C) 2015 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File :
 *          MyStruct
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
 *         MyStruct.cpp
 *
 * Notes :
 *          XXX
 *
 *****************************************************************************/

#include "MyStruct.h"

using namespace CONC;

MyStruct::MyStruct() :
		m_Value( 0 ),
		m_Mutex()
{
}

MyStruct::MyStruct( const uint8_t& value ) :
		m_Value( value ),
		m_Mutex()
{
}

bool MyStruct::operator ()( uint8_t& val )
{
	bool bResult = false;

	if ( m_Value > val )
	{
		std::lock_guard<std::mutex> guard( m_Mutex );
		val++;
		m_Value *= 3;

		bResult = true;
	}

	return bResult;
}

uint8_t MyStruct::getValue() const
{
	return m_Value;
}
