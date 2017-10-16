#ifndef FOOD_H_
#define FOOD_H_

#include <string>

namespace INT
{
	class Food
	{
		public:
			Food();

			const std::string& getNutrition() const;
			void setNutrition( const std::string& nutrition );

			const std::string& getWater() const;
			void setWater( const std::string& water );

		protected:
			//Not copyable
			Food( Food& );
			Food& operator=( Food& );

		private:
			std::string m_Water;
			std::string m_Nutrition;
	};
}
#endif
