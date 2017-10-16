#include "../../DSAndAlgorithms/ArrayOperations/ArrayOperations.h"

#include <cstdint> 
#include <iostream>

using namespace DSA;

ArrayOperations::ArrayOperations()
{
}

ArrayOperations::~ArrayOperations()
{
}

void ArrayOperations::performInsertion()
{
	uint8_t array[] = { 1, 3, 5, 7, 8 };

	uint8_t currentSize = 5;

	uint8_t newSize = currentSize + 1;

	uint8_t desiredIndex = 3;

	uint8_t elementToBeAdded = 10;

	while (currentSize >= desiredIndex)
	{
		array[currentSize+1] = array[currentSize];

		currentSize--;
	}

	array[desiredIndex] = elementToBeAdded;

	for ( auto i = 0; i < newSize ; ++i )
	{
		std::cout << "a[" << static_cast<uint32_t>(i) << "]: " 
			<< static_cast<uint32_t>(array[i]) << std::endl;
	}

}
