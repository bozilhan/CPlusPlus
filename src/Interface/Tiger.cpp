#include "Tiger.h"

#include <iostream>

using namespace INT;

Tiger::Tiger() :
	Feline()
{
	std::cout << "Tiger::Tiger" << std::endl;
}

Tiger::~Tiger()
{
	std::cout << "Tiger::~Tiger" << std::endl;
}

void Tiger::makeNoise()
{
	std::cout << "Tiger::makeNoise" << std::endl;
}

void Tiger::eat()
{
	std::cout << "Tiger::eat" << std::endl;
}
