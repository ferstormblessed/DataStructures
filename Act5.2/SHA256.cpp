#include "Dato.h"
#include "tablaHash.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
 
using namespace std;

int main(){
    HashTable ht(10000);
    vector<Dato> v;  // Vector donde se guardan los datos del archivo .txt
    vector<long long> VectorIps;
    ifstream ifs;
    ifs.open("bitacora.txt");
    string line, ip, temp;
    long long ipNum;
    while(getline(ifs, line)) {
        Dato d = Dato::leerString(line);
        v.push_back(d); //Se leen y se guardan los datos en el vector
        VectorIps.push_back(d.getIpNum()); //Agrega la ip a un vector de puras ips
    }
    ifs.close();
    
    for (int i=0; i<v.size(); i++) {
        ht.chain(VectorIps[i], v[i].getResumen());
    }

    ht.displayDetails("1");
    //ht.displayAll();
    return 0;
}