#ifndef DELEGATINGCONSTRUCTOR_H_
#define DELEGATINGCONSTRUCTOR_H_

#include <cstdint>

namespace KSI
{
	class DelegatingConstructor
	{
		public:
			DelegatingConstructor();

			DelegatingConstructor( const uint8_t& value );

			// Gereksizse sil CPP yi unutma
			virtual ~DelegatingConstructor();

			void printValue();

		protected:
			//Not copyable
			DelegatingConstructor( DelegatingConstructor& );
			DelegatingConstructor& operator=( DelegatingConstructor& );

		private:
			uint8_t m_Value;
	};
}
#endif
