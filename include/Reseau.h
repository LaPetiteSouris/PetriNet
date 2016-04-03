//
// Created by tung on 4/3/16.
//

#ifndef PETRINET_RESEAU_H
#define PETRINET_RESEAU_H

#include "Marquage.h"
#include "Matrice.h"
#include "Validation.h"

class Reseau {
public:
    Reseau();

    inline const Marquage get_marquage() const {
        return marquage;
    };

    inline const Matrice get_entree() const {
        return entree;
    };

    inline const Matrice get_sortie() const {
        return sortie;
    };

    void iterer();

    friend std::ostream &operator<<(std::ostream &stream, const Reseau &right);

    friend std::istream &operator>>(std::istream &stream, Reseau &right);

protected:
    Marquage marquage;
    Matrice entree;
    Matrice sortie;
    Validation validation;
};

#endif //PETRINET_RESEAU_H
