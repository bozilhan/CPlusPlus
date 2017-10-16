#ifndef CASTINGCLIENT_H_
#define CASTINGCLIENT_H_

#include "SpecialWidget.h"

namespace KSI
{
	class CastingClient
	{
		public:
			CastingClient();

			// Gereksizse sil CPP yi unutma
			virtual ~CastingClient();

			void update( SpecialWidget* psw )
			{

			}

		protected:
			//Not copyable
			CastingClient( CastingClient& );
			CastingClient& operator=( CastingClient& );

		private:

	};
}
#endif
