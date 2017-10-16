#ifndef WIDGET_H_
#define WIDGET_H_

namespace KSI
{
	class Widget
	{
		public:
			Widget();

			virtual ~Widget(){}


		protected:
			//Not copyable
			Widget( Widget& );
			Widget& operator=( Widget& );

		private:

	};
}
#endif
