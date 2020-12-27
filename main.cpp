#include <iostream>
#include "Counted.h"
#include <vector>
#include <memory>

using namespace std;

int main()
{
    std::vector<Counted> counteds = std::vector<Counted>();
    Counted c1 = Counted();
    Counted c2 = Counted();


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
