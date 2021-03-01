#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Counted
{
private:
  int id;
  static int count;
  static std::vector<int> id_vec;
  void set_id(std::vector<int> vec)
  {
      int temp_id = 0;
      int min_id = vec.front();

      for (unsigned int i = 0; i < vec.size(); i++)
      {
          if (vec[i] < min_id)
          {
              min_id = vec[i];
              temp_id = i;
          }
      }
      vec.erase(vec.begin() + temp_id);
      this->id = min_id;
  }

public:
  Counted()
  {
      if (id_vec.size() != 0)
         set_id(id_vec);
       id = ++count;
  }
  int get_id()
  {
      return id;
  }

  ~Counted()
  {
      id_vec.push_back(id);
      count--;
  }

  Counted(const Counted&) = delete;
  Counted(Counted&& other)
  {
      count = other.count;
  }

  Counted& operator=(const Counted&) = delete;
  Counted& operator=(Counted&& other)
  {
      if (this == &other)
        return *this;
      count = other.count;
      return *this;
  }
  static unsigned int get_count()
  {
      return count;
  }
};

int Counted::count = 0;
std::vector<int> Counted::id_vec = std::vector<int>();


int main()
{
    // Task 3 v1
    auto vec = vector<unique_ptr<Counted>>();
    vec.push_back(make_unique<Counted>());
    vec.push_back(make_unique<Counted>());
    vec.push_back(make_unique<Counted>());
    vec.push_back(make_unique<Counted>());
    for (const auto& it : v)
      cout << it->get_id() << endl;

    // Task 3 v2
    unique_ptr<Counted> a = make_unique<Counted>();
    unique_ptr<Counted> b = make_unique<Counted>();
    auto vect = vector<unique_ptr<Counted>>();
    vect.push_back(move(a));
    vect.push_back(move(b));
    for (const auto& i : vect)
        cout << i->get_id() << endl;

    return 0;
}

