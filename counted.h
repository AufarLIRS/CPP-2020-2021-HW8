#ifndef COUNTED_H
#define COUNTED_H

#include <algorithm>
#include <vector>
#include <set>
#include <memory>
class Counted
{
  int id;
  static int count;
  std::set<int> erased_id;
  int set_id();

public:
  int get_id();
  Counted();
  ~Counted();
  Counted& operator=(const Counted&&);
  Counted(Counted&&);
  Counted& operator=(const Counted&) = delete;
  Counted(const Counted&) = delete;
};

#endif
