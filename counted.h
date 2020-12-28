#ifndef COUNTED_H
#define COUNTED_H
#include <vector>
#include <iostream>

class Counted
{
  int id;
  static std::vector<int> freeId;
  static int count;

public:
  int getId();
  Counted();
  ~Counted();

  Counted(const Counted&) = delete;
  Counted& operator=(const Counted&) = delete;

  Counted(Counted&&);
  Counted& operator=(Counted&&);
};

#endif  // COUNTED_H
