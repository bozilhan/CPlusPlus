#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

namespace CH
{
	class Triangle : public Shape
	{
		public:
			Triangle();

			// Gereksizse sil CPP yi unutma
			virtual ~Triangle();

		protected:
			//Not copyable
			Triangle( Triangle& );
			Triangle& operator=( Triangle& );

		private:

	};
}
#endif
