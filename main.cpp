#include <iostream>
#include "counted.h"
using namespace std;

int main()
{
  Counted a1;
  Counted a2;
  Counted a3 = std::move(a2);

  cout << a1.getId() << endl;
  cout << a2.getId() << endl;
  cout << a3.getId() << endl;

  cout << "Task 2" << endl;
  auto v = vector<unique_ptr<Counted>>();
  v.push_back(make_unique<Counted>());
  v.push_back(make_unique<Counted>());
  for (const auto& i : v)
    cout << i->getId() << endl;

  cout << "Task 3" << endl;
  auto vec = vector<unique_ptr<Counted>>();
  ;
  vec.emplace_back(new Counted());
  vec.emplace_back(new Counted());
  for (const auto& i : vec)
    cout << i->getId() << endl;

  unique_ptr<Counted> a4 = make_unique<Counted>();
  unique_ptr<Counted> a5 = make_unique<Counted>();

  auto vect = vector<unique_ptr<Counted>>();
  vect.push_back(move(a4));
  vect.push_back(move(a5));
  for (const auto& i : vect)
    cout << i->getId() << endl;

  cout << "Task 4" << endl;
  auto vectr = vector<shared_ptr<Counted>>();
  vectr.push_back(make_shared<Counted>());
  vectr.push_back(make_shared<Counted>());

  for (const auto& i : vectr)
    cout << i->getId() << endl;

  return 0;
}
