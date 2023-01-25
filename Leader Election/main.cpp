#include "Graph.h"
#include "examples.cpp"
#include <iostream>

using namespace std;

int main()
{
    // NetworkGraf graf = primjerGraf1();
    NetworkGraf graf = primjerGraf2();
    // NetworkGraf graf = primjerGraf3();
    // NetworkGraf graf = primjerGraf4();
    // NetworkGraf graf = primjerGraf5();


    /** Leader election **/

    Cvor* vodja = graf.elekcijaVodje();
    cout << "\nFound leader for the given graph: " << vodja->port << ", with distance (reach): " << vodja->domet << "\n";
    graf.printKorijene();



    /** BFS Tree **/

    /*
    int korijen = 5;
    cout << "\nIteracija jednog BFS Stabla sa korijenom " << korijen << "\n";
    graf.BFS_Stablo(korijen , true, true);
    vector<Cvor*> cvorovi = graf.vratiCvorove();
    graf.printCvorovi(cvorovi);
    */


    /** Generate graph **/

    /*
    NetworkGraf graf2 = NetworkGraf::generisiNetworkGraf(20000, 10500);
    Cvor* vodja = graf2.elekcijaVodje();

    cout << "\nPronadjeni vodja za dati graf je: " << vodja->port << ", sa udaljenosti(dohvatom): " << vodja->domet << "\n";


    // graf2.printKorijene();
    // graf2.print();

    */

    return 0;
}
