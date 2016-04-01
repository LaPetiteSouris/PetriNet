//
// Created by tung on 4/1/16.
//
#include "../include/Marquage.h"


using namespace std;

Marquage::Marquage() {
    marqueurs = {0};
    places = 0;


};

const int Marquage::get_places() const {
    return marqueurs.size();
}

bool Marquage::operator==(const Marquage &right) const {
    if (places == right.places) {
        for (int i = 0; i++; i < places) {
            if (right(i) != (*this)(i)) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}


int Marquage::operator()(int place) const {
    try {
        return marqueurs.at(place);

    } catch (exception &e) {
        cout << e.what() << endl;
        throw;
    }
}

int &Marquage::operator()(int place) {
    try {
        return marqueurs.at(place);

    } catch (exception &e) {
        cout << e.what() << endl;
        throw;
    }
}


void Marquage::ajuster(int size) {
    marqueurs.resize(size, 0);
    places = size;

}


std::ostream &operator<<(std::ostream &str, const Marquage &right) {
    if (!right.marqueurs.empty()) {
        str << "(" << right.places << ") ";
        std::copy(right.marqueurs.begin(), right.marqueurs.end(), std::ostream_iterator<int>(str, ", "));
    }
    return str;
}


std::istream &operator>>(std::istream &str, Marquage &right) {
    int place(0);
    char p1, p2;
    str >> p1 >> place >> p2;
    right.ajuster(place);
    for (int i = 0; i < right.places; i++) {
        str >> right(i);
    }
    return str;

}


Marquage Marquage::operator+(const Marquage &n) const {
    Marquage result;
    if (this->places == n.places) {
        result.ajuster(this->places);
        for (int i = 0; i < this->places; i++) {
            result(i) = ((*this)(i) + n(i));
        }
        return result;

    }
    else {
        cout << "Vector dimenstion mismatched" << endl;
    }


}


Marquage Marquage::operator-(const Marquage &n) const {
    Marquage result;
    if (this->places == n.places) {
        result.ajuster(this->places);
        for (int i = 0; i < this->places; i++) {
            result(i) = ((*this)(i) - n(i));
        }
        return result;

    }
    else {
        cout << "Vector dimenstion mismatched" << endl;
    }

}









