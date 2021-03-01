#include <iostream>
#include "counted.h"
using namespace std;

Counted::Counted() {

    for (int i = 0; i < map.size(); i++) {

        if (map[i] == false) {
            id = i;
            map[i] = true;
            return;
        }
    }
    map[map.size()] = true;

}
Counted::~Counted() {

    map[this->id] = false;
    cout << "delete id" << endl;
}
