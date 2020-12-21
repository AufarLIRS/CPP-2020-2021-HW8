#include "counted.h"

int Counted::Number = 0;
std::vector<int> Counted::used_id = std::vector<int>();

int Counted::GetId()
{
  return Id;
}

void Counted::SetId(std::vector<int> vector)
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
  Id = vectorStart;
  vector.erase(vector.begin() + currentIndex);
}

Counted::Counted()
{
  if (!used_id.empty())
  {
    SetId(used_id);
  };

  Number++;
  Id = Number;
}

Counted::Counted(Counted&& NextId)
{
  Number = NextId.Number;
}

Counted& Counted::operator=(Counted&& NextId)
{
  if (this == &NextId)
  {
    Number = NextId.Number;
  }
  return *this;
}

Counted::~Counted()
{
  Number--;
  used_id.push_back(Id);
}
