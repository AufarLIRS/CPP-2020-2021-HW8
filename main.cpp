#include <iostream>
#include <counted.h>
#include <vector>

int main()
{
  std::cout << "Result: " << std::endl;

  Counted count1;
  Counted count2;
  Counted count3;

  std::cout << count1.getId() << std::endl;
  std::cout << count2.getId() << std::endl;
  std::cout << std::endl;

  Counted count4 = std::move(count3);
  std::cout << count3.getId() << std::endl;
  std::cout << count4.getId() << std::endl;
  std::cout << std::endl;

  //--------------------Task 2--------------------------
  auto myVec1 = std::vector<std::unique_ptr<Counted>>();
  myVec1.push_back(std::make_unique<Counted>());
  myVec1.push_back(std::make_unique<Counted>());

  for (const auto& i : myVec1)
  {
    std::cout << i->getId() << std::endl;
  }

  std::cout << std::endl;

  //--------------------Task 3a--------------------------
  auto myVec3 = std::vector<std::unique_ptr<Counted>>();
  myVec3.emplace_back(new Counted());
  myVec3.emplace_back(new Counted());

  for (const auto& i : myVec3)
  {
    std::cout << i->getId() << std::endl;
  }

  std::cout << std::endl;

  //--------------------Task 3b--------------------------
  auto count5 = std::make_unique<Counted>();
  auto count6 = std::make_unique<Counted>();

  auto myVec2 = std::vector<std::unique_ptr<Counted>>();
  myVec2.push_back(move(count5));
  myVec2.push_back(move(count6));

  for (const auto& i : myVec2)
  {
    std::cout << i->getId() << std::endl;
  }

  std::cout << std::endl;

  //--------------------Task 4--------------------------
  auto myVec4 = std::vector<std::shared_ptr<Counted>>();
  myVec4.push_back(std::make_shared<Counted>());
  myVec4.push_back(std::make_shared<Counted>());

  for (const auto& i : myVec4)
  {
    std::cout << i->getId() << std::endl;
  }

  std::cout << std::endl;

  return 0;
}
