#include "BSVectorUP.h"
#include <iostream>

using namespace CMA;

BSVectorUP::BSVectorUP() :
		m_pElemUP( std::unique_ptr<double>( new double() ) ),
		m_Sz( 3 )
{
	std::cerr << __LINE__ << " BSVectorUP::BSVectorUP()" << std::endl;
}

BSVectorUP::~BSVectorUP()
{
	std::cerr << __LINE__ << " BSVectorUP::~BSVectorUP()" << std::endl;
}

BSVectorUP::BSVectorUP( const BSVectorUP& rhs ) :
		m_pElemUP( std::unique_ptr<double>( new double( *rhs.m_pElemUP ) ) ),
		m_Sz( rhs.m_Sz )
{
	std::cerr << __LINE__ << " BSVectorUP::BSVectorUP( const BSVectorUP& rhs )" << std::endl;
}

BSVectorUP& BSVectorUP::operator =( const BSVectorUP& rhs )
{
	std::cerr << __LINE__ << " Enter - BSVectorUP::operator =( const BSVectorUP& rhs )" << std::endl;

	if ( this != &rhs )
	{
		m_pElemUP = std::unique_ptr<double>( new double( *rhs.m_pElemUP ) );

		m_Sz = rhs.m_Sz;
	}

	std::cerr << __LINE__ << " Exit - BSVectorUP::operator =( const BSVectorUP& rhs )" << std::endl;

	return *this;
}

BSVectorUP::BSVectorUP( BSVectorUP&& rhs ) :
		m_pElemUP( std::move( rhs.m_pElemUP ) ),
		m_Sz( rhs.m_Sz )
{
	std::cerr << __LINE__ << " Enter - BSVectorUP::BSVectorUP( BSVectorUP&& rhs )" << std::endl;

	rhs.m_pElemUP = nullptr;

	rhs.m_Sz = 0;

	std::cerr << __LINE__ << " Exit - BSVectorUP::BSVectorUP( BSVectorUP&& rhs )" << std::endl;
}

BSVectorUP& BSVectorUP::operator =( BSVectorUP&& rhs )
{
	std::cerr << __LINE__ << " Enter - BSVectorUP& BSVectorUP::operator =( BSVectorUP&& rhs )" << std::endl;

	if ( this != &rhs )
	{
		m_pElemUP = std::move( rhs.m_pElemUP );

		m_Sz = rhs.m_Sz;

		rhs.m_pElemUP = nullptr;

		rhs.m_Sz = 0;
	}

	std::cerr << __LINE__ << " Exit - BSVectorUP& BSVectorUP::operator =( BSVectorUP&& rhs )" << std::endl;

	return *this;
}

double* BSVectorUP::getElemUP() const
{
	return m_pElemUP.get();
}
