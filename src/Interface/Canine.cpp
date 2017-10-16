#include "Canine.h"

#include <iostream>

using namespace INT;

Canine::Canine() :
	Animal()
{
	std::cout << "Canine::Canine" << std::endl;
}

Canine::~Canine()
{
	std::cout << "Canine::~Canine" << std::endl;
}

void Canine::roam()
{
	std::cout << "Canine::roam" << std::endl;
}
