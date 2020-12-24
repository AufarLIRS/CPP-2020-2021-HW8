#include "counted.h"
#include <iostream>
#include <algorithm>

 int Counted::count = 0;
 std::vector<int> Counted::usersID = std::vector<int>();

 int Counted::getID()
 {
     return ID;
 }

 int getMinID(std::vector<int> newVector)
 {
    int minElementIndex = std::min_element(newVector.begin(), newVector.end()) - newVector.begin();
    int minElement = *std::min_element(newVector.begin(), newVector.end());
    newVector.erase(newVector.begin() + minElementIndex);
    return minElement;

 }

 Counted::Counted()
 {
   if (usersID.size() != 0)
   {
     ID = getMinID(usersID);
   }
   else if (count + 1 > 0)
   {
     count++;
     ID = count;
   }
   else
   {
     std::cout << "Error";
   }
 }

 Counted::Counted(Counted&& right)
 {
   count = right.count;
 }

 Counted& Counted::operator=(Counted&& right)
 {
   if (this != &right)
   {
     count = right.count;
   }
   return *this;
 }

 Counted::~Counted()
 {
   usersID.push_back(ID);
   count--;
 }
