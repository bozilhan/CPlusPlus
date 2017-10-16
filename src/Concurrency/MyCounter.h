#ifndef MYCOUNTER_H_
#define MYCOUNTER_H_

#include <cstdint>

namespace CONC
{
	class MyCounter
	{
		public:
			MyCounter();

			void increment();

			uint8_t getValue() const;

		private:
			uint8_t m_Value;
	};
}

#endif
