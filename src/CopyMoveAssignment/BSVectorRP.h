#ifndef BSVECTORRP_H_
#define BSVECTORRP_H_

#include <cstdint>

namespace CMA
{
	class BSVectorRP
	{
		public:
			BSVectorRP();
			~BSVectorRP();

			BSVectorRP( const BSVectorRP& rhs );
			BSVectorRP& operator=( const BSVectorRP& rhs );

			BSVectorRP( BSVectorRP&& rhs );
			BSVectorRP& operator=( BSVectorRP&& rhs );

			double* getElem() const;

		private:
			double* m_pElem;
			uint8_t m_Sz;
	};
}

#endif
