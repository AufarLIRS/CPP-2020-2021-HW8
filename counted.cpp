#include "counted.h"

int counted::Number = 0;
std::vector<int> counted::used_id = std::vector<int>();

int counted::getid()
{
  return id;
}

void counted::setid(std::vector<int> vector)
{
  int vectorStart = vector.front();
  int currentIndex = 0;
  for (unsigned int i = 0; i < vector.size(); i++)
  {
    if (vector[i] < vectorStart)
    {
      vectorStart = vector[i];
      currentIndex = i;
    }
  }
  id = vectorStart;
  vector.erase(vector.begin() + currentIndex);
}

counted::counted()
{
  if (!used_id.empty())
  {
    setid(used_id);
  };

  Number++;
  id = Number;
}

counted::counted(counted&& NextId)
{
  Number = NextId.Number;
}

counted& counted::operator=(counted&& NextId)
{
  if (this == &NextId)
  {
    Number = NextId.Number;
  }
  return *this;
}

counted::~counted()
{
  Number--;
  used_id.push_back(id);
}
