#include <iostream>
#include "counted.h"
#include <vector>
#include <memory>

int main()
{
  Counted one;
  Counted two;
  for (int i = 0; i < 3; i++)
  {
    Counted z;
  }
  std::cout << one.getID() << std::endl;
  std::cout << two.getID() << std::endl;

  Counted counted1 = Counted();
  std::cout << counted1.getID() << std::endl;
  Counted counted2(std::move(counted1));
  std::cout << counted2.getID() << std::endl;
  std::cout << counted1.getID() << std::endl;

  std::cout << "Task 3,4" << std::endl;

  std::vector<std::unique_ptr<Counted>> vector1;
  vector1.emplace_back(new Counted());
  vector1.emplace_back(new Counted());

  for (const auto& i : vector1)
  {
    std::cout << i->getID() << std::endl;
  }

  std::vector<std::unique_ptr<Counted>> vector2;
  vector2.push_back(std::make_unique<Counted>());
  vector2.push_back(std::make_unique<Counted>());

  for (const auto& i : vector2)
  {
    std::cout << i->getID() << std::endl;
  }

  std::vector<std::shared_ptr<Counted>> vector3;
  vector3.emplace_back(std::make_shared<Counted>());
  vector3.emplace_back(std::make_shared<Counted>());

  for (const auto& i : vector3)
  {
    std::cout << i->getID() << std::endl;
  }

  std::vector<Counted*> vector4;
  vector4.push_back(&one);
  vector4.push_back(&two);
  for (const auto& i : vector4)
  {
    std::cout << i->getID() << std::endl;
  }
}
