#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "Location.h"

#include <string>
#include <cstdint>
#include <memory>

namespace INT
{
	class Food;

	class Animal
	{
		public:
			Animal();

			virtual ~Animal();

			virtual void makeNoise() = 0;
			virtual void eat() = 0;
			void sleep();
			virtual void roam() = 0;

			uint8_t getBoundaries() const;
			void setBoundaries( const uint8_t& boundaries );

			const std::shared_ptr<Food>& getFood() const;
			void setFood( const std::shared_ptr<Food>& food );

			bool IsHunger() const;
			void setIsHunger( const bool& isHunger );

			const std::shared_ptr<Location>& getLocation() const;
			void setLocation( const std::shared_ptr<Location>& location );

			const std::string& getPicture() const;
			void setPicture( const std::string& picture );

		protected:
			//Not copyable
			Animal( Animal& );
			Animal& operator=( Animal& );

		private:
			std::shared_ptr<Location> m_pLocation;
			std::shared_ptr<Food> m_pFood;
			bool m_IsHunger;
			uint8_t m_Boundaries;
			std::string m_Picture;
	};
}
#endif
