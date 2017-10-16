#include "Implementation.h"

#include <iostream>
#include <algorithm>

using namespace DSAA;

std::vector<int> Implementation::getApples(const std::vector<int>& apple)
{
   std::vector<int> result;

   for (const auto& app : apple)
   {
      if (app > 0)
      {
         result.push_back(app);
      }
   }

   return result;
}

std::vector<int> Implementation::getOranges(const std::vector<int>& orange)
{
   std::vector<int> result;

   for (const auto& oran : orange)
   {
      if (oran < 0)
      {
         result.push_back(oran);
      }
   }

   return result;
}

void Implementation::performAppleAndOrange()
{
   int s = 2;
   int t = 3;
   int a = 1;
   int b = 5;
   std::vector<int> apple;
   apple.push_back(-2);

   std::vector<int> orange;
   orange.push_back(-1);

   std::vector<int> houseLocation;
   houseLocation.push_back(s);
   houseLocation.push_back(t);

   const auto& validApples = getApples(apple);
   const auto& validOranges = getOranges(orange);

   auto appleCount = 0;

   auto orangeCount = 0;

   for (const auto& locationAndFell : validApples)
   {
      //auto itApple = std::find_if(houseLocation.begin(),houseLocation.end(),[locationAndFell](int i){
      //   return (locationAndFell >= i);
      //});

      //if (itApple != houseLocation.end())
      //{
      //   if (houseLocation[1] < *itApple )
      //   {
      //   }
      //}

      if (s - a >= locationAndFell)
      {
         appleCount++;
      }
   }

   for (const auto& locationAndFell : validOranges)
   {
      if (b - t < std::abs(locationAndFell))
      {
         appleCount++;
      }

      //auto itApple = std::find_if(houseLocation.begin(),houseLocation.end(),[locationAndFell](int i){
      //   return (locationAndFell <= i);
      //});

      //if (itApple != houseLocation.end())
      //{
      //   if (houseLocation[0] > *itApple)
      //   {
      //      orangeCount++; 
      //   }
      //}
   }
   std::cout << appleCount << "\n" << orangeCount << std::endl;
}
// End Apple And Orange

// Begin Between Two Sets
short Implementation::validate(const int& num, const std::vector<int>& a , const std::vector<int>& b) {
   for (auto& _a : a) {
      if (num % _a)
         return 0;
   }
   for (auto& _b : b) {
      if (_b % num)
         return 0;
   }
   return 1;
}

int Implementation::getTotalX(std::vector <int> a, std::vector <int> b) {
   int start = a.back();
   int end = b.front(); // [start,end]

   int tmp = start;
   int count = 0;

   while(tmp <= end) {
      count += validate(tmp,a,b);
      tmp++;
   }

   return count;
}