//
// Created by tung on 4/1/16.
//

#ifndef PETRINET_MARQUAGE_H
#define PETRINET_MARQUAGE_H

#include <vector>
#include <istream>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class Marquage {

public:
    Marquage();

    inline const int get_places() const;

    void ajuster(int places);

    bool operator==(const Marquage &right) const;

    int &operator()(int place);

    int operator()(int place) const;

    Marquage operator+(const Marquage &right) const;

    Marquage operator-(const Marquage &right) const;

    friend std::ostream &operator<<(std::ostream &str, const Marquage &right);

    friend std::istream &operator>>(std::istream &str, Marquage &right);

protected:
    std::vector<int> marqueurs;
    int places;
};

#endif //PETRINET_MARQUAGE_H
