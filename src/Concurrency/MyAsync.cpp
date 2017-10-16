#include "MyAsync.h"

using namespace CONC;

MyAsync::MyAsync() :
		m_Value( 0 ),
		m_Mutex()
{
}

MyAsync::MyAsync( const uint8_t& value ) :
		m_Value( value ),
		m_Mutex()
{
}

bool MyAsync::operator ()( uint8_t& val )
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

uint8_t MyAsync::getValue() const
{
	return m_Value;
}

