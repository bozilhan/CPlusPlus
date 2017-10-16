#include "RecursirveFunctions.h"

#include <iostream>

using namespace KSI;

RecursirveFunctions::RecursirveFunctions()
{
}

RecursirveFunctions::~RecursirveFunctions()
{
}


void RecursirveFunctions::printStarRecursive( uint8_t nColumn )
{
	auto j = 0;

	for ( auto i = 0; i < nColumn ; ++i )
	{
		std::cout << "*";
	}

	if ( j > 0 )
	{
		printStarRecursive( j );
	}

	j--;

	std::cout << "\n";
}

void RecursirveFunctions::printStar( const uint8_t& nColumn, const uint8_t& nRow )
{
	for ( auto i = 0; i < nColumn ; ++i )
	{
		std::cout << "*";

		for ( auto j = i; j > 0 ; --j )
		{
			std::cout << "*";
		}

		std::cout << "\n";
	}
}
