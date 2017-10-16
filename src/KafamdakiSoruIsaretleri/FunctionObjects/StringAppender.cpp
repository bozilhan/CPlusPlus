#include "StringAppender.h"

using namespace KSI;

StringAppender::StringAppender() :
		m_ToAppend( "" )
{
}

KSI::StringAppender::StringAppender( const std::string& toAppend ) :
		m_ToAppend( toAppend )
{
}

std::string KSI::StringAppender::operator ()( const std::string& str ) const
{
	std::string strResult = str + " " + m_ToAppend;

	return strResult;
}
