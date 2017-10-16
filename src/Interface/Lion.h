#ifndef LION_H_
#define LION_H_

#include "Feline.h"

namespace INT
{
	class Lion : public Feline
	{
		public:
			Lion();

			virtual ~Lion();

			void makeNoise() override final;
			void eat() override final;

		protected:
			//Not copyable
			Lion( Lion& );
			Lion& operator=( Lion& );

		private:

	};
}
#endif
