#include <iostream>
#include "counted.h"
#include <vector>
#include <memory>


int main()
{
    Counted a;
    Counted b;
    for (int i = 0; i < 3; i++)
    {
        Counted d;
    }
    std::cout << a.getID() << std::endl;
    std::cout << b.getID() << std::endl;
    Counted c_1 = Counted();
    std::cout << c_1.getID() << std::endl;
    Counted c_2(std::move(c_1));
    std::cout << c_2.getID() << std::endl;
    std::cout << c_1.getID() << std::endl;
    std::vector<std::unique_ptr<Counted>> v_1;
    v_1.emplace_back(new Counted());
    v_1.emplace_back(new Counted());
    for (const auto& i : v_1)
    {
        std::cout << i->getID() << std::endl;
    }
    std::vector<std::unique_ptr<Counted>> v_2;
    v_2.push_back(std::make_unique<Counted>());
    v_2.push_back(std::make_unique<Counted>());
    for (const auto& i : v_2)
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
    vector4.push_back(&a);
    vector4.push_back(&b);
    for (const auto& i : vector4)
    {
        std::cout << i->getID() << std::endl;
    }
    return 1;
}
