#ifndef SMILEY_H_
#define SMILEY_H_

/******************************************************************************
 *
 * (C) 2015 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File :
 *          Smiley
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
 *         Smiley.h
 *
 * Notes :
 *          XXX
 *
 *****************************************************************************/

#include "Circle.h"

#include <vector>

namespace CH
{
	class Shape;

	class Smiley : public Circle
	{
		public:
			Smiley();

			explicit Smiley( const Point& point, const uint8_t& radius );

			~Smiley();

			const Point& center() const;

			void move( Point& to );

			void draw() const; //draw on current

			void rotate( const uint8_t& angle );

			void addEye( Shape* pShape );

			void setMouth( Shape* pMouth );

			virtual void wink( const uint8_t& i );

		private:
			std::vector<Shape*> m_Eyes;
			Shape* m_pMouth;
	};
}
#endif
