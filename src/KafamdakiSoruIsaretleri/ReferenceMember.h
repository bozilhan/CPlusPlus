#ifndef REFERENCEMEMBER_H_
#define REFERENCEMEMBER_H_

#include <cstdint>

namespace KSI
{
	class ReferenceMember
	{
		public:
			//ReferenceMember();

			explicit ReferenceMember( uint8_t& refMem );

			uint8_t& getRefMem() const
			{
				return m_RefMem;
			}

			void setRefMem( uint8_t& refMem )
			{
				m_RefMem = refMem;
			}

		private:
			uint8_t& m_RefMem;
	};
}
#endif
