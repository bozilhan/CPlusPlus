#ifndef CHRCLE_H_
#define CHRCLE_H_

/******************************************************************************
 *
 * (C) 2015 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File :
 *          Circle
 *
 * Purpose :
 *           XXX
 *
 * History :
 *
 * Date          Author                Changes
 * -----------   -------------------   --------------------------
 * 12.05.2015    bozilhan                Initial Release
 *
 * CSU ID :
 *          10-033-I-MARLIN
 *
 * Class :
 *         Circle.h
 *
 * Notes :
 *          XXX
 *
 *****************************************************************************/

#include "Shape.h"
#include "Point.h"

namespace CH
{
	class Circle : public Shape
	{
		public:
			Circle();

			explicit Circle( const Point& point, const uint8_t& radius );

			~Circle();

			const Point& center() const;

			void move( Point& to );

			void draw() const; //draw on current

			void rotate( const uint8_t& angle );

			void setRadius( const uint8_t& radius );

		private:
			Point m_Point; // Center
			uint8_t m_Radius;
	};
}
#endif
