#ifndef POINT_H_
#define POINT_H_

/******************************************************************************
 *
 * (C) 2015 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File :
 *          Point
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
 *         Point.h
 *
 * Notes :
 *          XXX
 *
 *****************************************************************************/

#include <cstdint>

namespace CH
{
	class Point
	{
		public:
			Point();
			~Point();

			uint8_t getX() const;
			void setX( const uint8_t& x );

			uint8_t getY() const;
			void setY( const uint8_t& y );

			void setXY( const uint8_t& x, const uint8_t& y );

		private:
			uint8_t m_X;
			uint8_t m_Y;
	};
}

#endif
