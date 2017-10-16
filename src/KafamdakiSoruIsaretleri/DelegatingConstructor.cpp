#include "DelegatingConstructor.h"

#include <iostream>

using namespace KSI;

DelegatingConstructor::DelegatingConstructor() :
	m_Value( 0 )
{
}

DelegatingConstructor::DelegatingConstructor( const uint8_t& value ) :
	//DelegatingConstructor(),
	m_Value( value )
{
}

DelegatingConstructor::~DelegatingConstructor()
{
}

void DelegatingConstructor::printValue()
{
	std::cout << "Value: " << (uint32_t)m_Value << std::endl;
}
