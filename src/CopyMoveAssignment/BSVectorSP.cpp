#include "BSVectorSP.h"
#include <iostream>

using namespace CMA;

BSVectorSP::BSVectorSP() :
		m_pElemSP( std::shared_ptr<double>( new double() ) ),
		m_Sz( 2 )
{
	std::cerr << __LINE__ << " BSVectorSP::BSVectorSP" << std::endl;
}

BSVectorSP::~BSVectorSP()
{
	std::cerr << __LINE__ << " BSVectorSP::~BSVectorSP" << std::endl;
}

BSVectorSP::BSVectorSP( const BSVectorSP& rhs ) :
		m_pElemSP( std::shared_ptr<double>( new double( *rhs.m_pElemSP ) ) ),
		m_Sz( rhs.m_Sz )
{
	std::cerr << __LINE__ << " BSVectorSP::BSVectorSP( const BSVectorSP& rhs )" << std::endl;
}

BSVectorSP& BSVectorSP::operator =( const BSVectorSP& rhs )
{
	std::cerr << __LINE__ << " Enter - BSVectorSP& BSVectorSP::operator =( const BSVectorSP& rhs )" << std::endl;

	if ( this != &rhs )
	{
		m_pElemSP = std::shared_ptr<double>( new double( *rhs.m_pElemSP ) );

		m_Sz = rhs.m_Sz;
	}

	std::cerr << __LINE__ << " Exit - BSVectorSP& BSVectorSP::operator =( const BSVectorSP& rhs )" << std::endl;

	return *this;
}

BSVectorSP::BSVectorSP( BSVectorSP&& rhs ) :
		m_pElemSP( rhs.m_pElemSP ),
		m_Sz( rhs.m_Sz )
{
	std::cerr << __LINE__ << " Enter - BSVectorSP::BSVectorSP( BSVectorSP&& rhs )" << std::endl;

	rhs.m_pElemSP = nullptr;

	rhs.m_Sz = 0;

	std::cerr << __LINE__ << " Exit - BSVectorSP::BSVectorSP( BSVectorSP&& rhs )" << std::endl;
}

BSVectorSP& BSVectorSP::operator =( BSVectorSP&& rhs )
{
	std::cerr << __LINE__ << " Enter - BSVectorSP& BSVectorSP::operator =( BSVectorSP&& rhs )" << std::endl;

	if ( this != &rhs )
	{
		m_pElemSP = rhs.m_pElemSP;

		m_Sz = rhs.m_Sz;

		rhs.m_pElemSP = nullptr;

		rhs.m_Sz = 0;
	}

	std::cerr << __LINE__ << " Exit - BSVectorSP& BSVectorSP::operator =( BSVectorSP&& rhs )" << std::endl;

	return *this;
}

std::shared_ptr<double> BSVectorSP::getElemSP() const
{
	return m_pElemSP;
}
