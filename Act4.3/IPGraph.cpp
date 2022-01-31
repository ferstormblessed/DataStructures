//Act 4.3 - Actividad Integral de Grafos (Evidencia Competencia)
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Domingo 21 de noviembre del 2021

#include "IPGraph.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

IPGraph::IPGraph() { //O(N), dependiendo del número de líneas de la bitácora
    reps = vector<int>(1000);
    adjList = vector<vector<int> >(1000);
    ifstream ifs;
    ifs.open("bitacora.txt");
    string line, ip, temp;
    int ipNum;
    while(getline(ifs, line)) {
        stringstream s(line);
        s >> temp >> temp >> temp >> ip; //Toma el valor de la IP y lo hace número
        ip = ip.substr(0, ip.find("."));
        ipNum = stoi(ip);
        reps[ipNum]++;
    }
    int sz = reps.size(); //Esto dura tiempo constante, considera los elementos de reps de 1-999
    for (int i=2; i<100 && i<sz; i++) {
        if (reps[i] > 0) {
            adjList[1].push_back(i);
		    adjList[i].push_back(1);
        }
    }
    for (int i=10; i<100; i+=10) {
        for (int j=0; j<100; j++) {
            if (reps[i*10+j] > 0) {
                adjList[i].push_back(i*10+j);
		        adjList[i*10+j].push_back(i);
            }
        }
    }
}

vector<int> IPGraph::maxFanOutLocation() { //O(1), el tamaño de AdjList siempre es el mismo
    int maxVal = 0;
    int maxInd, fanOut;
    vector<int> maxIndexes; 
    for (int i=1; i<adjList.size(); i++) {
        fanOut = adjList[i].size();
        if (fanOut > maxVal) {
            maxVal = fanOut;
            maxInd = i;
        }
    }
    maxIndexes.push_back(maxVal);
    for (int i=1; i<adjList.size(); i++) {
        fanOut = adjList[i].size();
        if (fanOut == maxVal) maxIndexes.push_back(i);
    }
    return maxIndexes; //Guarda en el índice 0 el valor máximo, y en el resto los nodos que tienen ese fan-out
}

vector<int> IPGraph::fanOut() { //O(1), el tamaño de AdjList siempre es el mismo
    vector<int> fanOutList(adjList.size());
    int fanOut;
    for (int i=1; i<adjList.size(); i++) { //Devuelve el fan-out de cada nodo
        fanOut = adjList[i].size();
        fanOutList[i] = fanOut;
    }
    return fanOutList;
}

pair<int,int> IPGraph::maxReps() { //O(N), reps si puede variar dependiendo de las IPs en el documento
    int maxVal = 0;
    int maxInd, rep;
    for (int i=1; i<reps.size(); i++) {
        rep = reps[i];
        if (rep > maxVal) {
            maxVal = rep;
            maxInd = i;
        }
    }
    return pair<int,int>(maxInd,maxVal); //La IP con más repeticiones y su número de repeticiones
}
