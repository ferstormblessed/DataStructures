//Act 4.3 - Actividad Integral de Grafos (Evidencia Competencia)
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Domingo 21 de noviembre del 2021

#ifndef IPGRAPH_H
#define IPGRAPH_H
#include <vector>
#include <utility>
using namespace std;

class IPGraph {
    public:
        IPGraph();
        vector<vector<int> > adjList;
        vector<int> reps;
        vector<int> maxFanOutLocation();
        vector<int> fanOut();
        pair<int,int> maxReps();
};

#endif