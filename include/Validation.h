//
// Created by tung on 4/1/16.
//

#ifndef PETRINET_VALIDATION_H
#define PETRINET_VALIDATION_H

#include <vector>
#include <iostream>
#include "Marquage.h"
#include "Matrice.h"

class Validation {

public:
    Validation();

    void valider(const Marquage &marquage, const Matrice &entree);

    Marquage marquer(const Matrice &matrice);

    friend std::ostream &operator<<(std::ostream &str, const Validation &right);

protected:

    std::vector<bool> validation;

};

#endif //PETRINET_VALIDATION_H
