#include "BSVector.h"

using namespace CMA;

BSVector::BSVector() :
		m_BSVectorRP(),
		m_BSVectorUP(),
		m_BSVectorSP()
{
}

BSVector::~BSVector()
{
}

BSVector::BSVector( const BSVector& rhs ) :
		m_BSVectorRP( rhs.m_BSVectorRP ),
		m_BSVectorUP( rhs.m_BSVectorUP ),
		m_BSVectorSP( rhs.m_BSVectorSP )
{
}

BSVector& BSVector::operator =( const BSVector& rhs )
{
	if ( this != &rhs )
	{
		m_BSVectorRP = rhs.m_BSVectorRP;
		m_BSVectorUP = rhs.m_BSVectorUP;
		m_BSVectorSP = rhs.m_BSVectorSP;
	}

	return *this;
}

BSVector::BSVector( BSVector&& rhs ) :
		m_BSVectorRP( std::move( rhs.m_BSVectorRP ) ),
		m_BSVectorUP( std::move( rhs.m_BSVectorUP ) ),
		m_BSVectorSP( std::move( rhs.m_BSVectorSP ) )
{
}

BSVector& BSVector::operator =( BSVector&& rhs )
{
	if ( this != &rhs )
	{
		m_BSVectorRP = std::move( rhs.m_BSVectorRP );
		m_BSVectorUP = std::move( rhs.m_BSVectorUP );
		m_BSVectorSP = std::move( rhs.m_BSVectorSP );
	}

	return *this;
}

BSVectorRP BSVector::getBSVectorRPRV() const
{
	return m_BSVectorRP;
}

BSVectorUP BSVector::getBSVectorUPRV() const
{
	return m_BSVectorUP;
}

BSVectorSP BSVector::getBSVectorSPRV() const
{
	return m_BSVectorSP;
}

BSVectorRP& BSVector::getBSVectorRPRR()
{
	return m_BSVectorRP;
}

BSVectorUP& BSVector::getBSVectorUPRR()
{
	return m_BSVectorUP;
}

BSVectorSP& BSVector::getBSVectorSPRR()
{
	return m_BSVectorSP;
}

const BSVectorRP& BSVector::getBSVectorRPCRR() const
{
	return m_BSVectorRP;
}

const BSVectorUP& BSVector::getBSVectorUPCRR() const
{
	return m_BSVectorUP;
}

const BSVectorSP& BSVector::getBSVectorSPCRR() const
{
	return m_BSVectorSP;
}

BSVectorRP BSVector::getBSVectorRPRVL()
{
	BSVectorRP vrp;

	return vrp;
}

BSVectorUP BSVector::getBSVectorUPRVL()
{
	BSVectorUP vup;

	return vup;
}

BSVectorSP BSVector::getBSVectorSPRVL()
{
	BSVectorSP vsp;

	return vsp;
}
