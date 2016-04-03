//
// Created by tung on 4/1/16.
//
#include "../include/Marquage.h"


using namespace std;

Marquage::Marquage() {
    marqueurs = {0};
    places = 0;


};


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


std::ostream &operator<<(std::ostream &stream, const Marquage &right) {
    if (!right.marqueurs.empty()) {
        stream << "(" << right.places << ") ";
        std::copy(right.marqueurs.begin(), right.marqueurs.end(), std::ostream_iterator<int>(stream, " "));
    }
    return stream;
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
    Marquage result, m1, m2;
    int place_max = n.get_places();
    if (this->get_places() > place_max) {
        place_max = this->get_places();
    }
    //Cloning
    m1.marqueurs = this->marqueurs;
    m2.marqueurs = n.marqueurs;
    //Reshaping
    m1.ajuster(place_max);
    m2.ajuster(place_max);
    result.ajuster(place_max);


    for (int i = 0; i < place_max; i++) {
        result(i) = m1(i) + m2(i);
    }
    return result;
}


Marquage Marquage::operator-(const Marquage &n) const {
    Marquage result, m1, m2;
    int place_max = n.get_places();
    if (this->get_places() > place_max) {
        place_max = this->get_places();
    }
    //Cloning
    m1.marqueurs = this->marqueurs;
    m2.marqueurs = n.marqueurs;
    //Reshaping
    m1.ajuster(place_max);
    m2.ajuster(place_max);
    result.ajuster(place_max);
    //Cloning

    for (int i = 0; i < place_max; i++) {
        result(i) = m1(i) - m2(i);
    }
    return result;

}









