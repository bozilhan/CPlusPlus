#include "Dog.h"

#include <iostream>

using namespace INT;

Dog::Dog() :
	Canine()
{
	std::cout << "Dog::Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog::~Dog" << std::endl;
}

void Dog::makeNoise()
{
	std::cout << "Dog::makeNoise" << std::endl;
}

void Dog::eat()
{
	std::cout << "Dog::eat" << std::endl;
}