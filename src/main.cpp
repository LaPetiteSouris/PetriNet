#include <iostream>
#include <sstream>
#include "../include/Marquage.h"
#include "../include/Matrice.h"
#include "../include/Validation.h"
#include "../include/Reseau.h"
#include "../include/Historique.h"

using namespace std;

int main() {
    //Test 1.1
    cout << "TEST 1.1 " << endl;
    Marquage m1;
    cout << "m1=" << m1 << endl;

    Marquage m2;
    m2.ajuster(5);
    cout << "m2=" << m2 << endl;

    m2(3) = 8;
    m2(2) = m2(3) - 3;
    cout << "m2=" << m2 << endl << endl;

    //Test 1.2
    cout << "TEST 1.2 " << endl;
    std::stringstream ss1;
    ss1 << "(5) 8 7 6 5 4 (3) 3 2 1" << std::ends;
    ss1 >> m1 >> m2;
    cout << m1 << m2 << endl << endl;

    //Test 1.3
    cout << "TEST 1.3 " << endl;
    Marquage m3;
    m3 = m2 + m1;
    cout << m3 << endl;
    m3 = m2 - m1;
    cout << m3 << endl << endl;



    //Test 2
    cout << "TEST 2 " << endl;
    Matrice x1;
    cout << "x1= " << x1 << endl;
    x1.ajuster(2, 3);
    cout << "x1= " << x1 << endl;
    std::stringstream ss2;
    ss2 << "(5 4) 4 5 1 2 6 7 3 4 8 9 5 6 7 8 9 1 2 3 4 5";
    ss2 >> x1;
    cout << "x1= " << x1 << endl;
    x1(1, 2) = x1(2, 1);
    cout << "x1= " << x1 << endl;
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
        cout << e.what() << endl << endl;
    }



    //Test 3
    cout << "TEST 3 " << endl;
    Validation vx;
    cout << "vx= " << vx << endl;
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
    cout << "vx= " << vx << endl;
    cout << "m0= " << m0 << endl;
    m0 = m0 - vx.marquer(entree);
    cout << "m0= " << m0 << endl << endl;

    // Test 4
    cout << "TEST 4 " << endl;
    Reseau rx;
    std::stringstream ss4;
    ss4 << "(5 4) 1 0 0 0   0 1 0 0   0 0 1 0  0 1 0 0    0 0 0 2 ";
    ss4 << "(5 4) 0 0 1 0   1 0 0 0   0 1 0 0    0 0 0 2  0 1 0 0 ";
    ss4 << "(5) 2 0 0 2 0 ";

    ss4 >> rx;
    cout << "rx= " << rx << endl;
    cout << "0.marquage= " << rx.get_marquage() << endl;
    rx.iterer();
    cout << "1.marquage= " << rx.get_marquage() << endl;
    rx.iterer();
    cout << "2.marquage= " << rx.get_marquage() << endl;;
    rx.iterer();
    cout << "3.marquage= " << rx.get_marquage() << endl;
    rx.iterer();
    cout << "4.marquage= " << rx.get_marquage() << endl << endl;

    //Test 5

    cout << "TEST 5 " << endl;
    Historique hx;
    try {

        hx.lancer(20);
    }
    catch (const char *err) {
        cout << err << endl;
    }

    Reseau ry;
    std::stringstream ss5;
    ss5 << "(5 4) 1 0 0 0   0 1 0 0   0 0 1 0  0 1 0 0    0 0 0 2 ";
    ss5 << "(5 4) 0 0 1 0   1 0 0 0   0 1 0 0    0 0 0 2  0 1 0 0 ";
    ss5 << "(5) 2 0 0 2 0 ";
    ss5 >> ry;
    cout << ry<<endl;
    hx.set_reseau(&ry);
    cout<<"Auto iteration: "<<endl;
    hx.lancer(20);
    cout << hx << endl;

    return 0;
}