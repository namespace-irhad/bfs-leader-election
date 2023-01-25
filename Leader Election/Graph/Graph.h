#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <random>
#include <chrono>


using namespace std;

class NetworkGraf
{
private:
    // CONGEST MODEL GRAF
    vector<vector<int>> matricaSusjedstva;      // Matrica susjedstva
    vector<Cvor*> cvorovi;                      // Vrhovi koji sadrze informacije
    vector<Cvor*> vodje;                        // Vektor vodja grafa
    int n;                                      // Broj cvorova u grafu
    bool usmjeren;                              // Usmjeren graf

public:
    NetworkGraf(int brojCvorova, bool usmjeren) : n(brojCvorova), usmjeren(usmjeren)
    {
        // Inicijalizacija matrice susjedstva
        matricaSusjedstva.resize(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            cvorovi.push_back(new Cvor(i));
    }

    void dodajGranu(int, int);
    void ukloniGranu(int, int);

    // BFS implementacija
    void BFS_Standard(int);
    vector<int> BFS_Stablo(int, bool = false, bool = false);

    // Elekcija vodje
    int BFS_Modifikacija_Stablo(int, int, vector<bool>, int&);
    Cvor* elekcijaVodje();
    void printKorijene();

    static NetworkGraf generisiNetworkGraf(int,int);
    vector<Cvor*> vratiVodje() { return vodje; }
    vector<Cvor*> vratiCvorove() {return cvorovi; }

    void print()
    {
        // Print matricu susjedstva
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matricaSusjedstva[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printCvorovi(vector<Cvor*>);
};

#endif // GRAPH_H
