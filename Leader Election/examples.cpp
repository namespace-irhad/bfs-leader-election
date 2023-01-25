#include "Graph.h"
#include <iostream>

using namespace std;

// Povezani graf
NetworkGraf primjerGraf1() {
    int broj_vrhova = 7;
    bool usmjeren = false;

    NetworkGraf graf(broj_vrhova, usmjeren);

    graf.dodajGranu(1, 0);
    graf.dodajGranu(2, 1);
    graf.dodajGranu(3, 2);
    graf.dodajGranu(3, 4);
    graf.dodajGranu(4, 5);
    graf.dodajGranu(5, 1);
    graf.dodajGranu(5, 6);
    graf.dodajGranu(4, 6);
    graf.dodajGranu(6, 0);

    return graf;
}

// Graf sa 3 komponente
NetworkGraf primjerGraf2() {
    int broj_vrhova = 8;
    bool usmjeren = false;

    NetworkGraf graf(broj_vrhova, usmjeren);

    graf.dodajGranu(3, 7);
    graf.dodajGranu(7, 1);
    graf.dodajGranu(1, 5);
    graf.dodajGranu(5, 4);
    graf.dodajGranu(4, 2);
    graf.dodajGranu(2, 6);

    return graf;
}

NetworkGraf primjerGraf3() {
    int broj_vrhova = 20;
    bool usmjeren = false;

    NetworkGraf graf(broj_vrhova, usmjeren);

    graf.dodajGranu(0, 1);
    graf.dodajGranu(0, 3);
    graf.dodajGranu(1, 2);
    graf.dodajGranu(1, 4);
    graf.dodajGranu(2, 5);
    graf.dodajGranu(3, 4);
    graf.dodajGranu(3, 6);
    graf.dodajGranu(4, 7);
    graf.dodajGranu(5, 8);
    graf.dodajGranu(6, 7);
    graf.dodajGranu(6, 9);
    graf.dodajGranu(7, 10);
    graf.dodajGranu(8, 11);
    graf.dodajGranu(9, 10);
    graf.dodajGranu(9, 12);
    graf.dodajGranu(10, 13);
    graf.dodajGranu(11, 14);
    graf.dodajGranu(12, 13);
    graf.dodajGranu(12, 15);
    graf.dodajGranu(13, 16);
    graf.dodajGranu(14, 15);
    graf.dodajGranu(14, 17);
    graf.dodajGranu(15, 18);
    graf.dodajGranu(16, 17);
    graf.dodajGranu(16, 19);
    graf.dodajGranu(17, 18);
    graf.dodajGranu(18, 19);

    return graf;
}

NetworkGraf primjerGraf4() {
    int broj_vrhova = 15;
    bool usmjeren = false;

    NetworkGraf graf(broj_vrhova, usmjeren);

    graf.dodajGranu(3, 4);
    graf.dodajGranu(3, 7);
    graf.dodajGranu(4, 5);
    graf.dodajGranu(5, 6);
    graf.dodajGranu(7, 8);
    graf.dodajGranu(8, 9);
    graf.dodajGranu(10, 11);
    graf.dodajGranu(11, 12);
    graf.dodajGranu(12, 13);
    graf.dodajGranu(13, 14);

    return graf;
}

NetworkGraf primjerGraf5() {
    int broj_vrhova = 37;
    bool usmjeren = false;

    NetworkGraf graf(broj_vrhova, usmjeren);

    graf.dodajGranu(1, 2);
    graf.dodajGranu(1, 5);
    graf.dodajGranu(2, 3);
    graf.dodajGranu(2, 4);
    graf.dodajGranu(3, 4);
    graf.dodajGranu(4, 5);
    graf.dodajGranu(6, 7);
    graf.dodajGranu(7, 8);
    graf.dodajGranu(8, 9);
    graf.dodajGranu(9, 10);
    graf.dodajGranu(10, 11);
    graf.dodajGranu(11, 12);
    graf.dodajGranu(12, 13);
    graf.dodajGranu(13, 14);
    graf.dodajGranu(14, 15);
    graf.dodajGranu(15, 16);
    graf.dodajGranu(16, 17);
    graf.dodajGranu(17, 18);
    graf.dodajGranu(18, 19);
    graf.dodajGranu(19, 20);
    graf.dodajGranu(20, 21);
    graf.dodajGranu(21, 22);
    graf.dodajGranu(22, 23);
    graf.dodajGranu(10, 15);
    graf.dodajGranu(10, 20);
    graf.dodajGranu(15, 25);
    graf.dodajGranu(20, 26);
    graf.dodajGranu(25, 27);
    graf.dodajGranu(26, 28);
    graf.dodajGranu(27, 29);
    graf.dodajGranu(28, 30);
    graf.dodajGranu(29, 31);
    graf.dodajGranu(30, 32);
    graf.dodajGranu(31, 33);
    graf.dodajGranu(32, 34);
    graf.dodajGranu(33, 35);
    graf.dodajGranu(34, 36);

    return graf;
}
