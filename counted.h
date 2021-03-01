#ifndef TASK1_H
#define TASK1_H
#include <map>


class Counted {
public:
        int id;
        static std::map<int, bool> map;

        Counted();

        ~Counted();


 };
#endif // TASK1_H
