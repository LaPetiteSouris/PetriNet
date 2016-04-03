//
// Created by tung on 4/3/16.
//
#include "../include/Validation.h"

Validation::Validation() {
}

std::ostream &operator<<(std::ostream &stream, const Validation &right) {
    stream << "(" << right.validation.size() << ")" << " ";
    std::copy(right.validation.begin(), right.validation.end(), std::ostream_iterator<int>(stream, " "));
    return stream;
}

void Validation::valider(const Marquage &marquage, const Matrice &entree) {
    if (entree.get_places() == marquage.get_places()) {
        validation.resize(entree.get_transitions());
        // validation(j) = { sur tout i : marquage(i) >= entree(i, j)
        for (int j = 0; j < validation.size(); j++) {
            validation.at(j) = true;
            for (int i = 0; i < marquage.get_places(); i++) {
                if (marquage(i) < entree(i, j)) {
                    validation.at(j) = false;
                }
            }
        }
    } else
        throw std::invalid_argument("Number of place mismatched between input argument");
}

Marquage Validation::marquer(const Matrice &matrice) {
    if (validation.size() == matrice.get_transitions()) {
        Marquage result;
        result.ajuster(matrice.get_places());
        // marquage T = marquage T – entree * validation T + sortie * validation T
        for (int i = 0; i < matrice.get_places(); i++) {
            for (int j = 0; j < matrice.get_transitions(); j++) {
                result(i) = result(i) + matrice(i, j) * validation.at(j);
            }
        }
        return result;
    }
    else
        throw std::invalid_argument("Number of transition mismatched between input argument");
}
