#include "counted.h"

int Counted::num = 0;
std::vector<int> Counted::used_id = std::vector<int>();
int Counted::getID()
{
    return ID;
}
void Counted::setID(std::vector<int> vector)
{
    int vStart = vector.front();
    int index = 0;
    for (unsigned int i = 0; i < vector.size(); i++)
    {
        if (vector[i] < vStart)
        {
            vStart = vector[i];
            index = i;
        }
    }
    ID = vStart;
    vector.erase(vector.begin() + index);
}
Counted::Counted()
{
    if (!used_id.empty())
    {
        setID(used_id);
    };
    num++;
    ID = num;
}

Counted::Counted(Counted&& NextId)
{
    num = NextId.num;
}

Counted& Counted::operator=(Counted&& NextId)
{
    if (this == &NextId)
    {
        num = NextId.num;
    }
    return *this;
}

Counted::~Counted()
{
    num--;
    used_id.push_back(ID);
}

