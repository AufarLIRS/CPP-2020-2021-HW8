#include "counted.h"

int Counted::count = 0;
std::vector<int> Counted::freeId = std::vector<int>();

int Counted::getId()
{
  return id;
}

int getMinId(std::vector<int> newVector)
{
  int min_count = newVector.front();
  int min_index = 0;

  for (unsigned int i = 0; i < newVector.size(); i++)
  {
    if (newVector[i] < min_count)
    {
      min_count = newVector[i];
      min_index = i;
    }
  }
  newVector.erase(newVector.begin() + min_index);

  return min_count;
}

Counted::Counted()
{
  if (freeId.size() != 0)
  {
    id = getMinId(freeId);
  }
  else if (count + 1 > 0)
  {
    count++;
    id = count;
  }
  else
  {
    std::cout << "Error";
  }
}

Counted::Counted(Counted&& right)
{
  count = right.count;
}

Counted& Counted::operator=(Counted&& right)
{
  if (this != &right)
  {
    count = right.count;
  }
  return *this;
}

Counted::~Counted()
{
  freeId.push_back(id);
  count--;
}
