#ifndef COUNTERBAPTISTEWITCH_H_
#define COUNTERBAPTISTEWITCH_H_

#include <cstdint>

#include <boost/log/common.hpp>

namespace KSI {
	class CounterBaptisteWitch {
		public:
			CounterBaptisteWitch();

			// Gereksizse sil CPP yi unutma
			virtual ~CounterBaptisteWitch();

			void incrementValue();


			void log( boost::log::formatting_ostream& os ) const;

			void log( std::ostream& os ) const;

			uint16_t getValue() const;

		protected:
			//Not copyable
			CounterBaptisteWitch( const CounterBaptisteWitch& rhs );
			CounterBaptisteWitch& operator=( const CounterBaptisteWitch& rhs );

		private:
			uint16_t m_Value;

	};
}

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, KSI::CounterBaptisteWitch& frame );

boost::log::formatting_ostream& operator<<( boost::log::formatting_ostream& os, const KSI::CounterBaptisteWitch& frame );

std::ostream& operator<<( std::ostream& os, KSI::CounterBaptisteWitch& frame );

std::ostream& operator<<( std::ostream& os, const KSI::CounterBaptisteWitch& frame );

#endif
