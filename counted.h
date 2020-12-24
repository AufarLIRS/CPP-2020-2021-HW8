#ifndef COUNTED_H
#define COUNTED_H
#include <vector>
#include<iostream>


class Counted
{
private:
    unsigned int ID;
    static std::vector<int> usersID;
    static int count;
public:
    Counted();
    Counted(const Counted&) = delete;
    Counted& operator=(const Counted&) = delete;
    Counted(Counted&&);
    Counted& operator=(Counted&&);
    ~Counted();
    int getID();
};

#endif // COUNTED_H
