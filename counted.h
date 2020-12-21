#ifndef COUNTED_H
#define COUNTED_H

#include <vector>
class Counted
{
  int id;
  static int count;
  static std::vector<int> id_vec;
  void setId(std::vector<int> newVector);

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
