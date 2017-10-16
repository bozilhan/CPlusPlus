#ifndef TIGER_H_
#define TIGER_H_

#include "Feline.h"

namespace INT
{
	class Tiger : public Feline
	{
		public:
			Tiger();

			virtual ~Tiger();

			void makeNoise() override final;
			void eat() override final;

		protected:
			//Not copyable
			Tiger( Tiger& );
			Tiger& operator=( Tiger& );

		private:

	};
}
#endif
