#include "Feline.h"

#include <iostream>

using namespace INT;

Feline::Feline() :
		Animal()
{
	std::cout << "Feline::Feline" << std::endl;
}

Feline::~Feline()
{
	std::cout << "Feline::~Feline" << std::endl;
}

void Feline::roam()
{
	std::cout << "Feline::roam" << std::endl;
}
