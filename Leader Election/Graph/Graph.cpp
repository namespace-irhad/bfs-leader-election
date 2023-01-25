#include "Graph.h"
#include <omp.h>

/// Add branch
void NetworkGraf::dodajGranu(int u, int v)
{
    // Graf je neusmjeren, dodaju se grane na oba cvora
    matricaSusjedstva[u][v] = 1;
    // Ukoliko je usmjeren, dodaje se grana samo za cvor od u do v
    if (!usmjeren) {
        matricaSusjedstva[v][u] = 1;
    }
}

/// Remove branch
void NetworkGraf::ukloniGranu(int u, int v)
{
    // Ukidanje grana cvorova u i v
    matricaSusjedstva[u][v] = 0;
    if (!usmjeren) {
        matricaSusjedstva[v][u] = 0;
    }
}

/** STANDARDNI BFS I BFS TREE **/
void NetworkGraf::BFS_Standard(int start) {
    vector<bool> posjecen(n, false);
    queue<int> q;
    q.push(start);
    posjecen[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (matricaSusjedstva[u][v] && !posjecen[v]) {
                posjecen[v] = true;
                q.push(v);
            }
        }
    }
}

vector<int> NetworkGraf::BFS_Stablo(int start, bool print, bool postaviCvor) {
    vector<int> roditelj(n, -1);
    vector<int> udaljenost(n, -1);
    vector<bool> posjecen(n, false);
    queue<int> q;

    q.push(start);
    posjecen[start] = true;
    udaljenost[start] = 0;

    if (postaviCvor)
        cvorovi[start]->udaljenostKorijen = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (matricaSusjedstva[u][v] && !posjecen[v]) {
                posjecen[v] = true;
                roditelj[v] = u;
                udaljenost[v] = udaljenost[u] + 1;

                if (postaviCvor)
                    cvorovi[u]->dijeca.push_back(v);
                    cvorovi[v]->roditelj = cvorovi[u];

                q.push(v);
            }
        }
    }

    if (print)
        for(int i = 0; i < n; i++){
            cout << "Cvor: " << i << " -> udaljenost od korijena: " << udaljenost[i] << endl;
        }

    return udaljenost;
}

/// Print BFS TREE result
void NetworkGraf::printCvorovi(vector<Cvor*> cvorovi) {
    int korijen = -1;
        for (int i = 0; i < cvorovi.size(); i++)
            if (!cvorovi[i]->roditelj && cvorovi[i]->dijeca.size() > 0)
                korijen = cvorovi[i]->port;

    cout << "\nKORIJEN: " << korijen << "\n";
    for (int i = 0; i < cvorovi.size(); i++) {
        cout << "PORT-> " << cvorovi[i]->port  << ", DIJECA SIZE-> " << cvorovi[i]->dijeca.size();
        if (cvorovi[i]->roditelj)
            cout << ", RODITELJ-> " << cvorovi[i]->roditelj->port << "\n";
        else
            cout << "\n";
    }
}

/** LEADER ELECTION **/
int NetworkGraf::BFS_Modifikacija_Stablo(int korijen, int trenutni, vector<bool> posjecen, int &udaljenost) {
    // Provjeri da li je korijen veci od trenutnog (korijen posjecuje susjedne cvorove i mijenja vodju ukoliko je veci od korijena)
    #pragma omp critical
    if (cvorovi[trenutni]->korijen > korijen) {
        cvorovi[trenutni]->korijen = korijen;
    }

    // Zaustavi program ukoliko je trenutni cvor manji od korijena (vodja ne moze biti korijen)
    if (trenutni < korijen) {
        #pragma omp critical
        cvorovi[korijen]->korijen = cvorovi[trenutni]->korijen;
        return udaljenost;
    }
    else {
        // Obiljezavamo trenutnog kao posjecen i povecavamo udaljenost za susjede
        posjecen[trenutni] = true;
        ++udaljenost;
        // Slanje poruka susjednim cvorovima
        for (int v = 0; v < n; v++) {
            if (matricaSusjedstva[trenutni][v] && !posjecen[v]) {
                int udaljenostOdTrenutnog = 0;
                posjecen[v] = true;
                BFS_Modifikacija_Stablo(korijen, v, posjecen, udaljenostOdTrenutnog);
                udaljenost += udaljenostOdTrenutnog;
            }
        }
    }
    return udaljenost;
}

Cvor* NetworkGraf::elekcijaVodje() {
    auto start = std::chrono::steady_clock::now();
    // Funkcija koja vraca pronadjenog vodju, u realnoj situaciji ovo nije potrebno jer informacija je potrebna samo cvorovima ne korisniku
    int najvecaUdaljenost = -1;
    int najmanjiIdentifikator = -1;
    int udaljenost = 0;
    vector<bool> posjecen(n, false);

    // Paralelno pozivanje BFS algoritma za sve cvorove unutar mreze
    #pragma omp for schedule(dynamic) private(udaljenost)
    for (int i = 0; i < n; i++) {
        // Interne informacije koje cuva svaki cvor prilikom slanja poruka
        udaljenost = 0;
        fill(posjecen.begin(), posjecen.end(), false);
        // Pratimo domet svakog cvora unutar mreze (dok se ne naidje na cvor sa manjim identifikatorom)
        int udaljenostOdNajmanjeg = BFS_Modifikacija_Stablo(i, i, posjecen, udaljenost);
        // Informacija koja ce korisniku prikazati najmanjeg cvora, ovo je informacija koja se vraca korisniku
        #pragma omp critical
        if (udaljenostOdNajmanjeg > najvecaUdaljenost) {
            najvecaUdaljenost = udaljenostOdNajmanjeg;
            najmanjiIdentifikator = i;
        }
    }
    auto end = std::chrono::steady_clock::now();
    chrono::duration<double, micro> vrMicro = end - start;
    cout << "Vrijeme: " << vrMicro.count() / 1000 << "ms\n";
    // Pronalazak vodje i postavljanje dometa
    Cvor* vodja = cvorovi[najmanjiIdentifikator];
    vodja->domet = najvecaUdaljenost;

    return vodja;
}

/// Print roots
void NetworkGraf::printKorijene() {
    cout << "CVOR | KORIJEN \n";
    for (int i = 0; i < n; i++)
        cout << i << " -> " << cvorovi[i]->korijen << "\n";
}

/** GENERATE GRAPH **/

NetworkGraf NetworkGraf::generisiNetworkGraf(int V, int E) {
    NetworkGraf g(V, false);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, V - 1);
    vector<bool> dodaniVrhovi(V * V, false);
    for (int i = 0; i < E; i++) {
        int u, v;
        do {
            u = dis(gen);
            v = dis(gen);
        } while (u == v || dodaniVrhovi[u * V + v]);
        dodaniVrhovi[u * V + v] = true;
        g.dodajGranu(u, v);
    }

    return g;
}
