//
// Created by tung on 4/3/16.
//

#include "../include/Reseau.h"

Reseau::Reseau() { }

void Reseau::iterer() {
    validation.valider(marquage, entree);
    marquage = marquage - validation.marquer(entree) + validation.marquer(sortie);
}

std::ostream &operator<<(std::ostream &stream, const Reseau &right) {
    stream << "Marque: " << right.marquage << endl;
    stream << "Entree: " << right.entree << endl;
    stream << "Sortiee: " << right.sortie << endl;
    return stream;
}

std::istream &operator>>(std::istream &stream, Reseau &right) {
    stream >> right.entree;
    stream >> right.sortie;
    stream >> right.marquage;
    return stream;


}