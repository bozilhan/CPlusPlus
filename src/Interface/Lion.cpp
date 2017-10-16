#include "Lion.h"

#include <iostream>

using namespace INT;

Lion::Lion() :
	Feline()
{
	std::cout << "Lion::Lion" << std::endl;
}

Lion::~Lion()
{
	std::cout << "Lion::~Lion" << std::endl;
}

void Lion::makeNoise()
{
	std::cout << "Lion::makeNoise" << std::endl;
}

void Lion::eat()
{
	std::cout << "Lion::eat" << std::endl;
}
