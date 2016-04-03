//
// Created by tung on 4/3/16.
//

#ifndef PETRINET_HISTORIQUE_H
#define PETRINET_HISTORIQUE_H

#include "Reseau.h"

using namespace std;

class Historique {
public:
    Historique();

    inline const Reseau *get_reseau() const
    {
        return reseau;
    };

    void set_reseau(Reseau *value);

    void lancer(int limite);

    friend std::ostream &operator<<(std::ostream &stream, const Historique &right);

protected:
    Reseau *reseau;
    std::vector<Marquage> marquages;
    bool initialized=false;
};

#endif //PETRINET_HISTORIQUE_H
