#ifndef LAUNDARY_H_
#define LAUNDARY_H_

#include <boost/log/common.hpp>

#include <mutex>
#include <condition_variable>

namespace CONC {

	class Laundary {
		public:
			// Parametreliyse explicit i unutma
			Laundary();

			// Gereksizse sil CPP yi unutma
			virtual ~Laundary();

			void log( boost::log::formatting_ostream& os ) const;

			void log( std::ostream& os ) const;

			void cleanLaundary();
			
			void playAround();

		protected:
			//Not copyable
			Laundary( const Laundary& rhs );
			Laundary& operator=( const Laundary& rhs );

			bool isLaundaryClean();
			
			bool isLaundaryDirty();

		private:
			enum class EnumLaundary{LAUNDARY_CLEAN, LAUNDARY_DIRTY};
			std::mutex m_Mutex;
			std::condition_variable m_ConditionVariable;
			EnumLaundary m_SonsLaundary;
	};
}

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, CONC::Laundary& frame );

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, const CONC::Laundary& frame );

std::ostream& operator<<( std::ostream& os, CONC::Laundary& frame );

std::ostream& operator<<( std::ostream& os, const CONC::Laundary frame );

#endif
