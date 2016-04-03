//
// Created by tung on 4/3/16.
//
#include "../include/Historique.h"


Historique::Historique() { }

void Historique::set_reseau(Reseau *val) {
    reseau = val;
    initialized = true;
}

void Historique::lancer(int limite) {
    if (initialized) {
        for (int i = 0; i < limite; i++) {
            reseau->iterer();
            marquages.push_back(reseau->get_marquage());
        }
    }
    else
        throw "Network not yet initialized";
}

std::ostream &operator<<(std::ostream &stream, const Historique &right) {
    //std::copy(right.marquages.begin(), right.marquages.end(), std::ostream_iterator<Marquage>(stream, " "));
    /* for (std::vector<Marquage>::const_iterator i = right.marquages.begin(); i != right.marquages.end(); ++i)
         stream << *i << ' ' << endl;
 */
    for (int i = 0; i < right.marquages.size(); i++) {
        stream << i << ". " << right.marquages.at(i) << endl;
    }

    return stream;
}
