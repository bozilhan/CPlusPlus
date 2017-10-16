#ifndef IMPLEMENTATION_H_
#define IMPLEMENTATION_H_

#include <vector>

namespace DSAA
{
   class Implementation
   {
   public:
      Implementation(){}

      // Begin Apple And Orange
      std::vector<int> getApples(const std::vector<int>& apple);
      std::vector<int> getOranges(const std::vector<int>& orange);
      void performAppleAndOrange();
      // End Apple And Orange

      // Begin Between Two Sets
       short validate(const int& num, const std::vector<int>& a , const std::vector<int>& b);
       int getTotalX(std::vector <int> a, std::vector <int> b);
      // EndBetween Two Sets

   protected:
      //Not copyable
      Implementation(const Implementation& rhs);
      Implementation& operator=(const Implementation& rhs);

   private:
   };
}

#endif
