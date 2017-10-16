#include <iostream>
#include <cstdint> 
#include <unordered_map>
#include <vector> 
#include <map> 
#include <algorithm> 
#include <cmath>

#include "DSAndAlgorithms/HackerRank/Algorithms/Implementation/Implementation.h"

using namespace std;

typedef std::map<uint8_t,uint8_t> MyMap;

vector<int> twoSum2(vector<int>& nums, int target) {

   vector<int> result;

   std::pair<std::vector<int>::iterator,std::vector<int>::iterator> bounds;

   std::sort (nums.begin(), nums.end());                     
   //bounds = std::for_each (nums.begin(), nums.end(),[target](int i, int j ){return(i+j); });  

   std::unordered_map<int,int> mm;

   for (auto i = 0; i< nums.size();i++)
   {
      mm[nums.at(i)] = i;
   }

   for (auto it = mm.begin(); it != mm.end(); ++it) 
   {
      auto search = mm.find(target - it->first);

      if(search != mm.end()) 
      {
         result.push_back(it->second);
      }
   }

   return result;
}

vector<int> twoSum(vector<int>& nums, int target) {
  
   vector<int> result;

   std::unordered_map<int,int> mm;

   for (auto i = 0; i< nums.size();i++)
   {
      mm[nums.at(i)] = i;
   }

   for (auto it = mm.begin(); it != mm.end(); ++it) 
   {
      auto search = mm.find(target - it->first);

      if(search != mm.end()) 
      {
         result.push_back(it->second);
      }
   }

   return result;
}

MyMap getPairs( const std::vector<uint8_t>& nums, const uint8_t& diff )
{
   MyMap result;

   MyMap mm;

   for (const auto& n : nums)
   {
   	mm[n] = 0;
   }

   for (auto it = mm.begin(); it != mm.end(); ++it) 
   {
      auto search = mm.find(it->first - 2);

      if(search != mm.end()) 
      {
         result[search->first] = it->first;
      }
   }

   return result;
}

int main(int, char **)
{
   std::cout << "Enter - Main" << std::endl;

   DSAA::Implementation imp;

   std::vector<int> a;
   a.push_back(2);
   a.push_back(4);

   std::vector<int> b;
   b.push_back(16);
   b.push_back(32);
   b.push_back(96);


   imp.getTotalX(a,b);

   const uint8_t& diff = 6;

   //const auto& mm = twoSum2(nums,diff);

   std::cout << "Exit- Main" << std::endl;

   return 0;
}
