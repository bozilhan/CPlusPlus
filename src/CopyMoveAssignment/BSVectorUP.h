#ifndef BSVECTORUP_H_
#define BSVECTORUP_H_

#include <cstdint>
#include <memory>

namespace CMA
{
	class BSVectorUP
	{
		public:
			BSVectorUP();

			~BSVectorUP();

			BSVectorUP( const BSVectorUP& rhs );
			BSVectorUP& operator=( const BSVectorUP& rhs );

			BSVectorUP( BSVectorUP&& rhs );
			BSVectorUP& operator=( BSVectorUP&& rhs );

			double* getElemUP() const;

		private:
			std::unique_ptr<double> m_pElemUP;
			uint8_t m_Sz;
	};
}

#endif
