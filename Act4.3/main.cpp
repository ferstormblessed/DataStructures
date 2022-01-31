//Act 4.3 - Actividad Integral de Grafos (Evidencia Competencia)
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Domingo 21 de noviembre del 2021

#include "IPGraph.h"
#include <iostream>
using namespace std;

int main() { //Obtiene los valores y los imprime en contexto
    IPGraph g;
    vector<int> fanOut = g.fanOut();
    vector<int> maxFanOut = g.maxFanOutLocation();
    pair<int,int> maxReps = g.maxReps();
    int maxRepsIndex = maxReps.first;
    int maxRepsVal = maxReps.second;
    cout << "El grafo indica que los nodos ";
    for (int i=1; i<maxFanOut.size(); i++) cout << maxFanOut[i] << ", ";
    cout << "tienen el mayor numero de conexiones, " << maxFanOut[0] << endl;
    cout << "Dado que todos estos nodos estan conectados al nodo 1, podemos inferir que ese nodo es el Bot Master." << endl;
    cout << "El log indica que el mayor numero de intentos (" << maxRepsVal << ") viene del nodo " << maxRepsIndex << endl;
    cout << "Fan-out de cada nodo: " << endl;
    for (int i=1; i<fanOut.size(); i++) {
        cout << "El nodo " << i << " tiene " << fanOut[i] << " conexiones y " << g.reps[i] << " intentos." << endl;
    }
    return 0;
}