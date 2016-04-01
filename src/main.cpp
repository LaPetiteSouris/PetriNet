#include <iostream>
#include <sstream>
#include "../include/Marquage.h"
using namespace std;

int main() {
    Marquage m1, m2;
   /* m2.ajuster(6);
    m1.ajuster(7);
    cout << m1<<m2<<endl;
*/
    std::stringstream ss1;
    ss1 << "(3) 6 5 4 (3) 7 2 1" << std::ends;
    ss1 >> m1 >> m2;
    cout<<m1<<m2<<endl;

    Marquage m3;
    m3=m1-m2;
    cout<<m3<<endl;
    return 0;
}