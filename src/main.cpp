#include <iostream>
#include <sstream>
#include "../include/Marquage.h"
#include "../include/Matrice.h"
#include "../include/Validation.h"

using namespace std;

int main() {/*
    Marquage m1, m2;
    m2.ajuster(6);
    m1.ajuster(7);
    cout << m1 << m2 << endl;

    std::stringstream ss1;
    ss1 << "(3) 6 5 4 (3) 7 2 1" << std::ends;
    ss1 >> m1 >> m2;
    cout << m1 << m2 << endl;

    Marquage m3;
    m3 = m1 - m2;
    cout << m3 << endl;
    Matrice x1;
    x1.ajuster(2, 3);
// ==> x1 = (2 3) 0 0 0 0 0 0
    std::stringstream ss2;
    ss2 << "(5 4) 4 5 1 2 6 7 3 4 8 9 5 6 7 8 9 1 2 3 4 5";
    ss2 >> x1;
    cout << x1 << endl;
    x1(1, 2) = x1(2, 1);
    cout << x1 << endl;
    try {
        x1(5, 2) = x1(2, 1);

    }
    catch (const std::invalid_argument &e) {
        cout << e.what() << endl;
    }
    try {
        x1(1, 4) = x1(2, 1);

    }
    catch (const std::invalid_argument &e) {
        cout << e.what() << endl;
    }
*/

    Validation vx;
// ==> vx = (0)
    std::stringstream ss3;
    ss3 << "(5) 2 0 0 2 0";
    ss3 << "(5 4) 1 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 2";
    ss3 << "(5 4) 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 2 0 1 0 0";
    Marquage m0;
    Matrice entree;
    Matrice sortie;
    ss3 >> m0 >> entree >> sortie;
    vx.valider(m0, entree);
    cout << vx << endl;
    cout << m0 << endl;
// ==> m0 = (5) 2 0 0 2 0
// ==> vx = (4) 1 0 0 0
    m0 = m0 - vx.marquer(entree);

    return 0;
}