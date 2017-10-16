#include "MyLRUCache.h"

//#include "Util/Logger/LogDef.h"

using namespace KSI;

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, MyLRUCache& frame ) {
	frame.log( os );
	return os;
}

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, const MyLRUCache& frame ) {
	frame.log( os );
	return os;
}

std::ostream& operator <<( std::ostream& os, MyLRUCache& frame ) {
	frame.log( os );
	return os;
}

std::ostream& operator <<( std::ostream& os, const MyLRUCache& frame ) {
	frame.log( os );
	return os;
}

MyLRUCache::MyLRUCache() :
	MyCache()
//,m_MemberOfMyCache(5)
{

	m_MemberOfMyCache = 6;
}

MyLRUCache::~MyLRUCache() {
}

void MyLRUCache::log( boost::log::formatting_ostream& os ) const {
	// TODO uint8_t char oldugundan memberin tipi uint8_t ise asagidaki casting gerekiyor
	//os << "\nValue: " << static_cast<uint32_t>(m_Value);
}

void MyLRUCache::log( std::ostream& os ) const {
	// TODO uint8_t char oldugundan memberin tipi uint8_t ise asagidaki casting gerekiyor
	//os << "\nValue: " << static_cast<uint32_t>(m_Value);
}

void MyLRUCache::foo() {
}
