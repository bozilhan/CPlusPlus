#ifndef BSVECTORSP_H_
#define BSVECTORSP_H_

#include <cstdint>
#include <memory>

namespace CMA
{
	class BSVectorSP
	{
		public:
			BSVectorSP();
			~BSVectorSP();

			BSVectorSP( const BSVectorSP& rhs );
			BSVectorSP& operator=( const BSVectorSP& rhs );

			BSVectorSP( BSVectorSP&& rhs );
			BSVectorSP& operator=( BSVectorSP&& rhs );

			std::shared_ptr<double> getElemSP() const;

		private:
			std::shared_ptr<double> m_pElemSP;
			uint8_t m_Sz;
	};
}

#endif
