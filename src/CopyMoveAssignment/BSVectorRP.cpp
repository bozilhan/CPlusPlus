#include "BSVectorRP.h"
#include <iostream>

using namespace CMA;

BSVectorRP::BSVectorRP() :
		m_pElem( new double ),
		m_Sz( 1 )
{
	std::cerr << __LINE__ << " BSVectorRP::BSVectorRP()" << std::endl;
}

BSVectorRP::~BSVectorRP()
{
	std::cerr << __LINE__ << " Enter - BSVectorRP::~BSVectorRP()" << std::endl;

	delete m_pElem;

	m_pElem = nullptr;

	std::cerr << __LINE__ << " Exit - BSVectorRP::~BSVectorRP()" << std::endl;
}

BSVectorRP::BSVectorRP( const BSVectorRP& rhs ) :
		m_pElem( new double ),
		m_Sz( rhs.m_Sz )
{
	std::cerr << __LINE__ << " Enter - BSVectorRP::BSVectorRP( const BSVectorRP& rhs )" << std::endl;

	*m_pElem = *rhs.m_pElem;

	std::cerr << __LINE__ << " Exit - BSVectorRP::BSVectorRP( const BSVectorRP& rhs )" << std::endl;
}

BSVectorRP& BSVectorRP::operator =( const BSVectorRP& rhs )
{
	std::cerr << __LINE__ << " Enter - BSVectorRP::operator =( const BSVectorRP& rhs )" << std::endl;

	if ( this != &rhs )
	{
		delete m_pElem;

		m_pElem = new double;

		*m_pElem = *rhs.m_pElem;

		m_Sz = rhs.m_Sz;
	}

	std::cerr << __LINE__ << " Exit - BSVectorRP::operator =( const BSVectorRP& rhs )" << std::endl;

	return *this;
}

BSVectorRP::BSVectorRP( BSVectorRP&& rhs ) :
		m_pElem( rhs.m_pElem ),
		m_Sz( rhs.m_Sz )
{
	std::cerr << __LINE__ << " Enter - BSVectorRP::BSVectorRP( BSVectorRP&& rhs )" << std::endl;

	rhs.m_pElem = nullptr;
	rhs.m_Sz = 0;

	std::cerr << __LINE__ << " Exit - BSVectorRP::BSVectorRP( BSVectorRP&& rhs )" << std::endl;
}

BSVectorRP& BSVectorRP::operator =( BSVectorRP&& rhs )
{
	std::cerr << __LINE__ << " Enter - BSVectorRP::operator =( BSVectorRP&& rhs )" << std::endl;

	if ( this != &rhs )
	{
		delete m_pElem;

		m_pElem = new double;

		*m_pElem = *rhs.m_pElem;

		m_Sz = rhs.m_Sz;

		rhs.m_pElem = nullptr;

		rhs.m_Sz = 0;
	}

	std::cerr << __LINE__ << " Exit - BSVectorRP::operator =( BSVectorRP&& rhs )" << std::endl;

	return *this;
}

double* BSVectorRP::getElem() const
{
	return m_pElem;
}
