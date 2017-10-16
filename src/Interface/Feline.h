#ifndef FELINE_H_
#define FELINE_H_

#include "Animal.h"

namespace INT
{
	class Feline : public Animal
	{
		public:
			virtual ~Feline();

			void roam() override final;

		protected:
			Feline();

			//Not copyable
			Feline( Feline& );
			Feline& operator=( Feline& );

		private:

	};
}
#endif
