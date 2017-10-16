#include "MyClass.h"

using namespace KSI;

MyClass::MyClass() :
		m_Member( 0 )
{
}

MyClass::MyClass( const MyClass& rhs ) :
	m_Member( rhs.m_Member )
{
}

MyClass& MyClass::operator =( const MyClass& rhs )
{
	if ( this != &rhs )
	{
		m_Member = rhs.m_Member;
	}

	return *this;
}

MyClass::MyClass( MyClass&& rhs ) :
		m_Member( rhs.m_Member )
{
	rhs.m_Member = 0;
}

KSI::MyClass::~MyClass()
{
	m_Member = 0;
}

MyClass& MyClass::operator =( MyClass&& rhs )
{
	if ( this != &rhs )
	{
		m_Member = rhs.m_Member;

		rhs.m_Member = 0;
	}

	return *this;
}

uint8_t MyClass::getMember() const
{
	return m_Member;
}

void MyClass::setMember( const uint8_t& member )
{
	m_Member = member;
}
