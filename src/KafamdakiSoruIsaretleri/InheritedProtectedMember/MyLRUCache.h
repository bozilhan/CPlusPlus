#ifndef MYLRUCACHE_H_
#define MYLRUCACHE_H_

#include <boost/log/common.hpp>

#include "MyCache.h"

namespace KSI {

	class MyLRUCache : public MyCache{
		public:
			// Parametreliyse explicit i unutma
			MyLRUCache();

			// Gereksizse sil CPP yi unutma
			virtual ~MyLRUCache();

			void log( boost::log::formatting_ostream& os ) const;

			void log( std::ostream& os ) const;

			void foo() override final;

		protected:
			//Not copyable
			MyLRUCache( const MyLRUCache& rhs );
			MyLRUCache& operator=( const MyLRUCache& rhs );

		private:

	};
}

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, KSI::MyLRUCache& frame );

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, const KSI::MyLRUCache& frame );

std::ostream& operator<<( std::ostream& os, KSI::MyLRUCache& frame );

std::ostream& operator<<( std::ostream& os, const KSI::MyLRUCache frame );

#endif
