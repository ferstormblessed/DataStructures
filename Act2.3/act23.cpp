//Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia) 
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Lunes 11 de octubre del 2021

#include "Dato.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>  

using namespace std;

int main() {
    vector<Dato> v;  // Vector donde se guardan los datos del archivo .txt
    ifstream ifs;
    ifs.open("bitacora.txt");
    string line;
    while(getline(ifs, line)) {
        v.push_back(Dato::leerString(line)); //Se leen y se guardan los datos en el vector
    }
    Dato::ordenar(v); //Se ordena el vector
    ifs.close();

    ofstream ofs; // Registra los datos ordenados en salida.txt
    ofs.open("salida.txt");
    for (Dato d : v) ofs << Dato::toString(d);
    ofs.close();

    string ipInit, ipFin;
    cout << "Introduzca la IP inicial en el formato XXX.XX.XXX.XXX:XXXX" << endl;
    cin >> ipInit;
    Dato datoI("Mes", 0, "00:00:00", ipInit, "None");
    int indInit = Dato::buscar(v, datoI);

    cout << "Introduzca la IP final en el formato XXX.XX.XXX.XXX:XXXX" << endl;
    cin >> ipFin;
    Dato datoF("Mes", 0, "00:00:00", ipFin, "None");
    int indFin = Dato::buscar(v, datoF);

    //Se imprimen todos los datos entre los indices inicial y final, correspondientes a las entradas
    for (int i=indInit; i<=indFin; i++) cout << Dato::toString(v[i]);
    cin.get();
    return 0;
} 