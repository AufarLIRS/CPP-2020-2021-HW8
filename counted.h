#ifndef COUNTED_H
#define COUNTED_H

#include <vector>
#include <memory>

class counted
{
private:
  static std::vector<int> used_id;
  int id;
  void setid(std::vector<int> vector);
  static int Number;

public:
  int getid();
  counted();
  ~counted();

  counted(const counted&) = delete;
  counted& operator=(const counted&) = delete;

  counted(counted&&);
  counted& operator=(counted&&);
};

#endif
