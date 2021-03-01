#include <iostream>
#include "counted.h"
using namespace std;
#include <vector>

std::map<int,bool> Counted::map;
int main()
{
    Counted counted1;
    Counted counted2;
    Counted counted3;
    std::vector<Counted> vector1 = {counted1, counted2, counted3};

        Counted* counted4 = new Counted();
        delete counted4;
        Counted counted5;

        for(const auto& i:vector1){
            //task3, добавление в вектор по индексации
            // вывод ID объектов, чтобы убедиться, что все работает как надо
            std::cout << i.id << std::endl;
        }



    return 0;
}
