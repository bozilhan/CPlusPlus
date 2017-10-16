#ifndef LOCATION_H_
#define LOCATION_H_

#include <cstdint>

namespace INT
{
	class Location
	{
		public:
			Location();

			uint8_t getX() const;
			void setX( const uint8_t& x );

			uint8_t getY() const;
			void setY( const uint8_t& y );

			void setXY( const uint8_t& x, const uint8_t& y );

		protected:
			//Not copyable
			Location( Location& );
			Location& operator=( Location& );

		private:
			uint8_t m_X;
			uint8_t m_Y;
	};
}
#endif
