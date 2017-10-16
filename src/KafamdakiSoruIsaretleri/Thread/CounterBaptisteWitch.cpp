#include "CounterBaptisteWitch.h"

using namespace KSI;

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, CounterBaptisteWitch& frame ) {
	frame.log( os );
	return os;
}

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, const CounterBaptisteWitch& frame ) {
	frame.log( os );
	return os;
}

std::ostream& operator <<( std::ostream& os, CounterBaptisteWitch& frame ) {
	frame.log( os );
	return os;
}

std::ostream& operator <<( std::ostream& os, const CounterBaptisteWitch& frame ) {
	frame.log( os );
	return os;
}

CounterBaptisteWitch::CounterBaptisteWitch() :
		m_Value( 0 ) {
}

CounterBaptisteWitch::~CounterBaptisteWitch() {
}

void CounterBaptisteWitch::incrementValue() {
	++m_Value;
}

void CounterBaptisteWitch::log( boost::log::formatting_ostream& os ) const {
	os << "\nValue: " << m_Value;
}

void CounterBaptisteWitch::log( std::ostream& os ) const {
	os << "\nValue: " << m_Value;
}

uint16_t CounterBaptisteWitch::getValue() const {
	return m_Value;
}


