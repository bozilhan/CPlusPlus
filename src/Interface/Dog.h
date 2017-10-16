#ifndef DOG_H_
#define DOG_H_

#include "Canine.h"

namespace INT
{
	class Dog : public Canine
	{
		public:
			Dog();

			virtual ~Dog();

			void makeNoise() override final;
			void eat() override final;

		protected:
			//Not copyable
			Dog( Dog& );
			Dog& operator=( Dog& );

		private:

	};
}
#endif
