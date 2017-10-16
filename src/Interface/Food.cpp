#include "Food.h"

using namespace INT;

Food::Food() :
	m_Water(""),
	m_Nutrition("")
{
}

const std::string& Food::getNutrition() const
{
	return m_Nutrition;
}

void Food::setNutrition( const std::string& nutrition )
{
	m_Nutrition = nutrition;
}

const std::string& Food::getWater() const
{
	return m_Water;
}

void Food::setWater( const std::string& water )
{
	m_Water = water;
}
