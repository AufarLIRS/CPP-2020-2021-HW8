#include "counted.h"

int Counted::count = 0;
std::vector<int> Counted::id_vec = std::vector<int>();

int Counted::getId()
{
  return id;
}
void Counted::setId(std::vector<int> new_vec)
{
  int temp_index = 0;
  int min_id = new_vec.front();

  for (unsigned int i = 0; i < new_vec.size(); i++)
  {
    if (new_vec[i] < min_id)
    {
      min_id = new_vec[i];
      temp_index = i;
    }
  }

  new_vec.erase(new_vec.begin() + temp_index);
  id = min_id;
}

Counted::Counted()
{
  if (id_vec.size() != 0)
  {
    setId(id_vec);
  }
  count++;
  id = count;
}
Counted::~Counted()
{
  id_vec.push_back(id);
  count--;
}
Counted::Counted(Counted&& other)
{
  count = other.count;
}
Counted& Counted::operator=(Counted&& other)
{
  if (this == &other)
    return *this;
  count = other.count;
  return *this;
}
