#ifndef COUNTED_H
#define COUNTED_H
#include <iostream>
#include <set>
#include <iostream>
#include <algorithm>

class Counted
{
  int ID;
  std::set<int> DeletedID;
  static int count;
  int setID();

public:
  int getID();
  Counted();
  ~Counted();
  Counted(const Counted&) = delete;
  Counted& operator=(const Counted&) = delete;  //так как противоречит условию уникальности
  Counted(Counted&&);
  Counted& operator=(const Counted&&);
};

#endif  // COUNTED_H
