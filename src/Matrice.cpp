//
// Created by tung on 4/1/16.
//
#include "../include/Matrice.h"


Matrice::Matrice() {
    places = 0;
    transitions = 0;
    arcs.resize(places * transitions, 0);
}

const int Matrice::get_places() const {
    return places;
}

const int Matrice::get_transitions() const {
    return transitions;
}


int Matrice::operator()(int place, int transition) const {
    return arcs.at(clef(place, transition));
}

int &Matrice::operator()(int place, int transition) {
    return arcs.at(clef(place, transition));
}

int Matrice::clef(int place, int transition) const {
    if (place >= places) {
        throw std::invalid_argument("place value exceeds total places available");
    }
    if (transition >= transitions) {
        throw std::invalid_argument("transition value exceeds total transitions available");
    }
    return transition + place * transitions;
}

void Matrice::ajuster(int place, int transition) {
    places = place;
    transitions = transition;
    arcs.resize(place * transitions, 0);

}


std::ostream &operator<<(std::ostream &stream, const Matrice &right) {
    stream << "(" << right.get_places() << " " << right.get_transitions() << ")";
    std::copy(right.arcs.begin(), right.arcs.end(), std::ostream_iterator<int>(stream, " "));
    return stream;
}

std::istream &operator>>(std::istream &stream, Matrice &right) {
    int place(0), trans(0);
    char p1, p2;
    stream >> p1 >> place >> trans >> p2;
    right.ajuster(place, trans);
    for (int i = 0; i < right.get_places(); i++) {
        for (int j = 0; j < right.get_transitions(); j++)
            stream >> right(i, j);
    }
    return stream;
}