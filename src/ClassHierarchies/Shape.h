#ifndef SHAPE_H_
#define SHAPE_H_

/******************************************************************************
 *
 * (C) 2015 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File :
 *          Shape
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
 *         Shape.h
 *
 * Notes :
 *          XXX
 *
 *****************************************************************************/

#include "Point.h"

namespace CH
{
	class Shape
	{
		public:
			virtual ~Shape(){}

			virtual const Point& center() const = 0;

			virtual void move( Point& to ) = 0;

			virtual void draw() const = 0; //draw on current

			virtual void rotate( const uint8_t& angle ) = 0;
	};
}

#endif
