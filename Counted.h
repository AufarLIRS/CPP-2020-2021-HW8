#ifndef COUNTED_H
#define COUNTED_H

#include <vector>
#include <memory>

class Counted
{
private:
  static std::vector<int> used_id;
  int Id;
  void SetId(std::vector<int> vector);
  static int Number;

public:
  int GetId();
  Counted();
  ~Counted();

  Counted(const Counted&) = delete;
  Counted& operator=(const Counted&) = delete;

  Counted(Counted&&);
  Counted& operator=(Counted&&);
};

#endif  // COUNTED_H
