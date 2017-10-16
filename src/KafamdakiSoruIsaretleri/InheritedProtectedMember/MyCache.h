#ifndef MYCACHE_H_
#define MYCACHE_H_

#include <cstdint>

namespace KSI {

	class MyCache {
		public:
			MyCache() :
					m_MemberOfMyCache( 0 ) {
			}

			virtual ~MyCache() {
			}

			virtual void foo() = 0;

		protected:
			//Not copyable
			MyCache( const MyCache& rhs );
			MyCache& operator=( const MyCache& rhs );

		protected:
			uint8_t m_MemberOfMyCache;
	};
}

#endif
