#ifndef SPECIALWIDGET_H_
#define SPECIALWIDGET_H_

#include "Widget.h"

namespace KSI
{
	class SpecialWidget : public Widget
	{
		public:
			SpecialWidget():
				Widget()
			{}

		protected:
			//Not copyable
			SpecialWidget( SpecialWidget& );
			SpecialWidget& operator=( SpecialWidget& );

		private:

	};
}
#endif
