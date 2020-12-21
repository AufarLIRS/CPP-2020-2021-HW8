#include <iostream>
#include "Counted.h"

int main()
{
  // Task 1
  Counted a;
  Counted b;
  std::cout << "Task 1" << std::endl;
  std::cout << "a - " << a.GetId() << std::endl;
  std::cout << "b - " << b.GetId() << std::endl;

  // Task 2
  // auto vector = std::vector<Counted>();
  // vector.push_back(a); - use of deleted function 'Counted::Counted(const Counted&)'
  // vector.push_back(b); - use of deleted function 'Counted::Counted(const Counted&)'

  // Task 3
  // Method 1
  std::cout << "Task 3" << std::endl << "Method 1" << std::endl;
  auto c = std::make_unique<Counted>();
  auto d = std::make_unique<Counted>();
  auto vector = std::vector<std::unique_ptr<Counted>>();

  vector.push_back(move(c));
  vector.push_back(move(d));

  int k = 0;
  for (const auto& i : vector)
  {
    k++;
    // вывод ID объектов, чтобы убедиться, что все работает как надо
    std::cout << k << " - " << i->GetId() << std::endl;
  }
  k = 0;

  // Method 2
  std::cout << "Method 2" << std::endl;
  auto vector2 = std::vector<std::unique_ptr<Counted>>();
  vector2.emplace_back(new Counted());
  vector2.emplace_back(new Counted());

  for (const auto& i : vector2)
  {
    k++;
    // вывод ID объектов, чтобы убедиться, что все работает как надо
    std::cout << k << " - " << i->GetId() << std::endl;
  }
  k = 0;

  // Task 4
  // Method 3
  std::cout << "Task 4" << std::endl << "Method 3" << std::endl;
  auto vector3 = std::vector<std::shared_ptr<Counted>>();
  auto e = std::make_shared<Counted>();
  auto f = std::make_shared<Counted>();
  vector3.push_back(e);
  vector3.push_back(f);

  for (const auto& i : vector3)
  {
    k++;
    // вывод ID объектов, чтобы убедиться, что все работает как надо
    std::cout << k << " - " << i->GetId() << std::endl;
  }
  return 0;
}
