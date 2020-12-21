#include "counted.h"

int Counted::count;

int Counted::set_id()
{
  if (erased_id.empty())
  {
    count++;
    return count;
  }
  else
  {
    count++;
    int deleted_id = *erased_id.begin();
    erased_id.erase(0);
    return deleted_id;
  }
}

int Counted::get_id()
{
  return id;
}
Counted::Counted()
{
  id = set_id();
}

Counted::~Counted()
{
  if (id == count)
  {
    count--;
    return;
  }
  count--;
  erased_id.insert(id);
}

Counted& Counted::operator=(const Counted&& item)
{
  if (&item != this)
  {
    id = std::move(item.id);
  }
  return *this;
}

Counted::Counted(Counted&& item)
{
  if (&item != this)
  {
    id = std::move(item.id);
  }
}
