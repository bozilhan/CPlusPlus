#ifndef MYSTRUCT_H_
#define MYSTRUCT_H_

#include <cstdint>
#include <mutex>

namespace CONC
{
	class MyStruct
	{
		public:
			MyStruct();

			explicit MyStruct( const uint8_t& value );

			bool operator()( uint8_t& val );

			uint8_t getValue() const;

		private:
			uint8_t m_Value;
			std::mutex m_Mutex;
	};
}

#endif
