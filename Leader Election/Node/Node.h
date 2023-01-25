#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <random>

using namespace std;

class Cvor
{
    public:
        Cvor(int p) : port(p), udaljenostKorijen(-1), roditelj(nullptr), korijen(p), kreiranoPodstablo(-1), domet(-1) {}
        int port;
        int udaljenostKorijen;
        Cvor* roditelj;
        int korijen;
        vector<Cvor> dijeca;
        int kreiranoPodstablo;
        int domet;

    private:
};

#endif // NODE_H
