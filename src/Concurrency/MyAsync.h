#ifndef MYASYNC_H_
#define MYASYNC_H_

#include <cstdint>
#include <mutex>

namespace CONC
{
	class MyAsync
	{
		public:
			MyAsync();

			explicit MyAsync( const uint8_t& value );

			bool operator()( uint8_t& val );

			uint8_t getValue() const;

		private:
			uint8_t m_Value;
			std::mutex m_Mutex;
	};
}
#endif
