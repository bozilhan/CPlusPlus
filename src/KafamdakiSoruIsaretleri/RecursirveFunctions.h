#ifndef RECURSIRVEFUNCTIONS_H_
#define RECURSIRVEFUNCTIONS_H_

#include <cstdint>

namespace KSI
{
	class RecursirveFunctions
	{
		public:
			RecursirveFunctions();
			~RecursirveFunctions();

			void printStarRecursive( uint8_t nColumn );

			void printStar( const uint8_t& nColumn, const uint8_t& nRow );
	};
}
#endif
