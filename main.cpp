#include <iostream>
#include "counted.h"

int main()
{
  // Task 1
  counted a;
  counted b;
  std::cout << "Task 1" << std::endl;
  std::cout << "a - " << a.getid() << std::endl;
  std::cout << "b - " << b.getid() << std::endl;

  // Task 2
  //- use of deleted function 'counted::counted(const counted&)'
  // auto vector1 = std::vector<counted>();
  // vector1.push_back(a);
  // vector1.push_back(b);

  // Task 3
  std::cout << "Task 3" << std::endl;
  auto c = std::make_unique<counted>();
  auto d = std::make_unique<counted>();
  auto vector = std::vector<std::unique_ptr<counted>>();

  vector.push_back(move(c));
  vector.push_back(move(d));

  int k = 0;
  for (const auto& i : vector)
  {
    k++;
    std::cout << k << " - " << i->getid() << std::endl;
  }
  k = 0;
  // Task 4
  std::cout << "Task 4" << std::endl;
  auto vector3 = std::vector<std::shared_ptr<counted>>();
  auto e = std::make_shared<counted>();
  auto f = std::make_shared<counted>();
  vector3.push_back(e);
  vector3.push_back(f);

  for (const auto& i : vector3)
  {
    k++;
    std::cout << k << " - " << i->getid() << std::endl;
  }
  return 0;
}
