//
// Created by tung on 4/1/16.
//
#include "../include/Marquage.h"


using namespace std;

Marquage::Marquage() {
    marqueurs = {0};


};

const int Marquage::get_places() const {
    return marqueurs.size();
}

bool Marquage::operator==(const Marquage &right) const {
    vector<string> v3;

    sort(this->marqueurs.begin(), this->marqueurs.end());
    sort(right.marqueurs.begin(), right.marqueurs.end());

    set_intersection(this->marqueurs.begin(), this->marqueurs.end(), right.marqueurs.begin(), right.marqueurs.end(),
                     back_inserter(v3));

    if (v3.size() == 0) {
        return true;
    }
    return false;


}


int Marquage::operator()(int place) const {
    return marqueurs.at(place);
}

int &Marquage::operator()(int place) {
    return marqueurs.at(place);
}


void Marquage::ajuster(int size) {
    marqueurs.resize(size, 0);

}


std::ostream &operator<<(std::ostream &str, const Marquage &right) {
    if (!right.marqueurs.empty()) {
        str << "(" << right.places << ") ";
        std::copy(right.marqueurs.begin(), right.marqueurs.end(), std::ostream_iterator<int>(str, ", "));
    }
    return str;
}


std::istream &operator>>(std::istream &str, Marquage &right) {

}


Marquage Marquage::operator+(const Marquage &n) const {

}


Marquage Marquage::operator-(const Marquage &n) const {

}

}







