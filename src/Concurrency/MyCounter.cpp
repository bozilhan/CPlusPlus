#include "MyCounter.h"

using namespace CONC;

MyCounter::MyCounter() :
		m_Value( 0 )
{
}

void MyCounter::increment()
{
	++m_Value;
}

uint8_t MyCounter::getValue() const
{
	return m_Value;
}
