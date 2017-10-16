#include "Wolf.h"

#include <iostream>

using namespace INT;

Wolf::Wolf() :
	Canine()
{
	std::cout << "Wolf::Wolf" << std::endl;
}

Wolf::~Wolf()
{
	std::cout << "Wolf::~Wolf" << std::endl;
}

void Wolf::makeNoise()
{
	std::cout << "Wolf::makeNoise" << std::endl;
}

void Wolf::eat()
{
	std::cout << "Wolf::eat" << std::endl;
}
