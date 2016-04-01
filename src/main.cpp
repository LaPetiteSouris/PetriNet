#include <iostream>
#include <sstream>
#include "../include/Marquage.h"
#include "../include/Matrice.h"

using namespace std;

int main() {
    Marquage m1, m2;
    /* m2.ajuster(6);
     m1.ajuster(7);
     cout << m1<<m2<<endl;

     std::stringstream ss1;
     ss1 << "(3) 6 5 4 (3) 7 2 1" << std::ends;
     ss1 >> m1 >> m2;
     cout<<m1<<m2<<endl;

     Marquage m3;
     m3=m1-m2;
     cout<<m3<<endl;*/

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

    return 0;
}