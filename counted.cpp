#include "counted.h"
#include <algorithm>

void Counted::set_id()
{
  std::vector<bool>::iterator it = std::find(ids_.begin(), ids_.end(), false);
  id_ = std::distance(ids_.begin(), it) + 1;
  if (it == ids_.end())
  {
    ids_.push_back(true);
  }
  else
  {
    ids_.at(id_ - 1) = true;
  }
}
std::vector<bool> Counted::ids_ = std::vector<bool>();
Counted::Counted()
{
  set_id();
}
Counted::Counted(Counted&& counted)
{
  if (&counted != this)
  {
    id_ = std::move(counted.id_);
  }
}
Counted& Counted::operator=(Counted&& counted)
{
  if (&counted != this)
  {
    id_ = std::move(counted.id_);
  }
  return *this;
}
std::ostream& operator<<(std::ostream& os, const Counted& obj)
{
  os << obj.id_;
  return os;
}
Counted::~Counted()
{
  if ((int)ids_.size() == id_)
  {
    ids_.pop_back();
  }
  else
  {
    ids_.at(id_ - 1) = false;
  }
  while (!ids_.back())
  {
    ids_.pop_back();
  }
}
