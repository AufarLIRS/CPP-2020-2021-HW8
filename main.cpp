#include <iostream>
#include "counted.h"

int main()
{
  Counted first;
  Counted second = std::move(first);
  Counted third = std::move(second);

  std::cout << first.get_id() << std::endl;
  std::cout << second.get_id() << std::endl;
  std::cout << third.get_id() << std::endl;

  // task2----------------------------------------------

  auto vec1 = std::vector<std::unique_ptr<Counted>>();

  vec1.push_back(std::make_unique<Counted>());
  for (const auto& i : vec1)
    std::cout << i->get_id() << std::endl;

  // task3----------------------------------------------

  auto vec2 = std::vector<std::unique_ptr<Counted>>();

  vec2.emplace_back(new Counted());
  for (const auto& i : vec2)
    std::cout << i->get_id() << std::endl;

  std::unique_ptr<Counted> fourth = std::make_unique<Counted>();
  auto vec3 = std::vector<std::unique_ptr<Counted>>();

  vec3.push_back(move(fourth));
  for (const auto& i : vec3)
    std::cout << i->get_id() << std::endl;

  // task4----------------------------------------------

  auto vec4 = std::vector<std::unique_ptr<Counted>>();
  vec4.emplace(vec4.end());
  vec4.emplace(vec4.end());
  for (const auto& i : vec4)
    std::cout << i->get_id() << std::endl;

  return 0;
}
