#include "Laundary.h"
#include <iostream>

//#include "Util/Logger/LogDef.h"

using namespace CONC;

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, Laundary& frame ) {
	frame.log( os );
	return os;
}

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, const Laundary& frame ) {
	frame.log( os );
	return os;
}

std::ostream& operator <<( std::ostream& os, Laundary& frame ) {
	frame.log( os );
	return os;
}

std::ostream& operator <<( std::ostream& os, const Laundary& frame ) {
	frame.log( os );
	return os;
}

Laundary::Laundary() :
		m_Mutex(),
		m_ConditionVariable(),
		m_SonsLaundary( EnumLaundary::LAUNDARY_CLEAN ) {
}

Laundary::~Laundary() {
}

void Laundary::log( boost::log::formatting_ostream& os ) const {
	// TODO uint8_t char oldugundan memberin tipi uint8_t ise asagidaki casting gerekiyor
	//os << "\nValue: " << static_cast<uint32_t>( m_Value );
}

void Laundary::log( std::ostream& os ) const {
	// TODO uint8_t char oldugundan memberin tipi uint8_t ise asagidaki casting gerekiyor
	//os << "\nValue: " << static_cast<uint32_t>( m_Value );
}

// m_SonsLaundary describes the state of laundary
bool Laundary::isLaundaryClean() {
	return m_SonsLaundary == EnumLaundary::LAUNDARY_CLEAN;
}

bool Laundary::isLaundaryDirty() {
	return m_SonsLaundary == EnumLaundary::LAUNDARY_DIRTY;
}

// jakascorner.com Condition Variable kismindan aciklamayi kopyala
void Laundary::cleanLaundary() {

	std::unique_lock<std::mutex> lock( m_Mutex );

	//m_ConditionVariable.wait( lock, [this]() {return this->isLaundaryClean ();});

	m_ConditionVariable.wait( lock, std::bind( &Laundary::isLaundaryDirty, this ) );

	std::cout << "Doing the son's laundary" << std::endl;

	m_SonsLaundary = EnumLaundary::LAUNDARY_CLEAN;

	//lock.unlock();

	m_ConditionVariable.notify_one();
}

void Laundary::playAround() {
	
	std::cout << "Playing basketball and sweating" << std::endl;
	{
		std::lock_guard<std::mutex> lock(m_Mutex);

		m_SonsLaundary = EnumLaundary::LAUNDARY_DIRTY;
	}
	
	std::cout << "Asking mother to do the laundary" << std::endl;
	
	m_ConditionVariable.notify_one();

	//waiting
	{
		std::unique_lock<std::mutex> lock( m_Mutex );

		m_ConditionVariable.wait( lock, std::bind( &Laundary::isLaundaryClean, this ) );
	}

	std::cout << "Yea, I have clean laundary! Thank you mum!" << std::endl;
}

