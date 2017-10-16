#include "STLContainerIlklendirme.h"

using namespace KSI;

STLContainerIlklendirme::STLContainerIlklendirme() :
	m_Vector()
{
}

STLContainerIlklendirme::~STLContainerIlklendirme()
{
}

const std::vector<uint8_t>& KSI::STLContainerIlklendirme::getVector() const
{
	return m_Vector;
}
