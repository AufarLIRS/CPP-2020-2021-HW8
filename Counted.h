#ifndef COUNTED_H
#define COUNTED_H

#include <iostream>
#include <vector>

class Counted
{
private:
  static std::vector<bool> ids_;
  int id_ = 0;
  void set_id();

public:
  Counted();
  Counted(const Counted&) = delete;
  Counted& operator=(const Counted&) = delete;
  Counted(Counted&&);
  Counted& operator=(Counted&&);
  friend std::ostream& operator<<(std::ostream& os, const Counted& obj);
  ~Counted();


};

#endif // COUNTED_H
