#include "WhenCopyWhenAssignment.h"

#include <utility>

using namespace KSI;

WhenCopyWhenAssignment::WhenCopyWhenAssignment() :
		m_MyClass()
{
}

WhenCopyWhenAssignment::WhenCopyWhenAssignment( const WhenCopyWhenAssignment& rhs ) :
		m_MyClass( rhs.m_MyClass )
{
}

WhenCopyWhenAssignment& WhenCopyWhenAssignment::operator =( const WhenCopyWhenAssignment& rhs )
{
	if ( this != &rhs )
	{
		m_MyClass = rhs.m_MyClass;
	}

	return *this;
}

WhenCopyWhenAssignment::WhenCopyWhenAssignment( WhenCopyWhenAssignment&& rhs ) :
		m_MyClass( std::move( rhs.m_MyClass ) )
{
}

WhenCopyWhenAssignment& WhenCopyWhenAssignment::operator =( WhenCopyWhenAssignment&& rhs )
{
	if ( this != &rhs )
	{
		m_MyClass = std::move( rhs.m_MyClass );
	}

	return *this;
}

const MyClass& WhenCopyWhenAssignment::getMyClass() const
{
	return m_MyClass;
}

void WhenCopyWhenAssignment::setMyClass( const MyClass& myClass )
{
	m_MyClass = myClass;
}

MyClass WhenCopyWhenAssignment::getMyClassLocal() const
{
	MyClass myClassLocal;

	return myClassLocal;
}
