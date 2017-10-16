#ifndef CANINE_H_
#define CANINE_H_

#include "Animal.h"

namespace INT
{
	class Canine : public Animal
	{
		public:
			virtual ~Canine();

			void roam() override final;

		protected:
			Canine();

			//Not copyable
			Canine( Canine& );
			Canine& operator=( Canine& );
	};
}
#endif
