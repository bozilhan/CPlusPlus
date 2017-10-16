#ifndef STLCONTAINERILKLENDIRME_H_
#define STLCONTAINERILKLENDIRME_H_

#include <vector>
#include <cstdint>
namespace KSI
{
	class STLContainerIlklendirme
	{
		public:
			STLContainerIlklendirme();

			// Gereksizse sil CPP yi unutma
			virtual ~STLContainerIlklendirme();

			const std::vector<uint8_t>& getVector() const;

		protected:
			//Not copyable
			STLContainerIlklendirme( STLContainerIlklendirme& );
			STLContainerIlklendirme& operator=( STLContainerIlklendirme& );

		private:
			std::vector<uint8_t> m_Vector;
	};
}
#endif
