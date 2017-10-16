#include "Animal.h"
#include "Food.h"

#include <iostream>

using namespace INT;

Animal::Animal() :
		m_pLocation( std::shared_ptr<Location>( new Location() ) ),
		m_pFood( std::shared_ptr<Food>( new Food() ) ),
		m_IsHunger( false ),
		m_Boundaries( 0 ),
		m_Picture( "" )
{
	std::cout << "Animal::Animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal::~Animal" << std::endl;
}

void Animal::sleep()
{
	std::cout << "Animal::sleep" << std::endl;
}

uint8_t Animal::getBoundaries() const
{
	return m_Boundaries;
}

void Animal::setBoundaries( const uint8_t& boundaries )
{
	m_Boundaries = boundaries;
}

const std::shared_ptr<Food>& Animal::getFood() const
{
	return m_pFood;
}

void Animal::setFood( const std::shared_ptr<Food>& food )
{
	m_pFood = food;
}

bool Animal::IsHunger() const
{
	return m_IsHunger;
}

void Animal::setIsHunger( const bool& isHunger )
{
	m_IsHunger = isHunger;
}

const std::shared_ptr<Location>& Animal::getLocation() const
{
	return m_pLocation;
}

void Animal::setLocation( const std::shared_ptr<Location>& location )
{
	m_pLocation = location;
}

const std::string& Animal::getPicture() const
{
	return m_Picture;
}

void Animal::setPicture( const std::string& picture )
{
	m_Picture = picture;
}
