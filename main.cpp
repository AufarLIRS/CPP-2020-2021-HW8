#include <iostream>
#include <counted.h>
#include <vector>
#include <memory>

int main()
{
  //  Counted counted1 = Counted();
  //  std::cout << counted1.get_id() << std::endl;
  //  Counted counted2(std::move(counted1));
  //  std::cout << counted2.get_id() << std::endl;
  //  std::cout << counted1.get_id() << std::endl;

  std::vector<Counted> counteds = std::vector<Counted>();
  Counted c1 = Counted();
  Counted c2 = Counted();
  // counteds.push_back(c1);

  std::vector<Counted*> vector1 = { &c1, &c2 };
  for (const auto& i : vector1)
  {
    std::cout << *i << std::endl;
  }

  std::vector<std::shared_ptr<Counted>> vector2 = { std::make_shared<Counted>(), std::make_shared<Counted>() };
  for (const auto& i : vector2)
  {
    std::cout << *i << std::endl;
  }

  std::vector<Counted> vector3(2);
  for (const auto& i : vector3)
  {
    std::cout << i << std::endl;
  }

  std::vector<Counted> vector4;
  vector4.emplace(vector4.end());
  vector4.emplace(vector4.end());
  for (const auto& i : vector4)
  {
    std::cout << i << std::endl;
  }

  return 0;
}
