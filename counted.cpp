#include "counted.h"

int Counted::count;

int Counted::getID()
{
  return ID;
}
int Counted::setID()
{
  if (DeletedID.empty())
  {
    count++;
    return count;
  }
  else
  {
    count++;
    int deleted_id = *DeletedID.begin();
    DeletedID.erase(0);
    return deleted_id;
  }
}
Counted::Counted()
{
  ID = setID();
}
Counted::~Counted()
{
  if (ID == count)
  {
    count--;
    return;
  }
  count--;
  DeletedID.insert(ID);
}

Counted::Counted(Counted&& original)
{
  if (&original != this)
  {
    ID = std::move(original.ID);
  }
}

Counted& Counted::operator=(const Counted&& original)
{
  if (&original != this)
  {
    ID = std::move(original.ID);
  }
  return *this;
}
