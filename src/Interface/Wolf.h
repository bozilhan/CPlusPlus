#ifndef WOLF_H_
#define WOLF_H_

#include "Canine.h"

namespace INT
{
	class Wolf : public Canine
	{
		public:
			Wolf();

			virtual ~Wolf();

			void makeNoise() override final;
			void eat() override final;

		protected:
			//Not copyable
			Wolf( Wolf& );
			Wolf& operator=( Wolf& );
	};
}
#endif
