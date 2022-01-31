//Act 1.3 Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia) 
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Domingo 12 de spetiembre del 2021

#include "Dato.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

void swap(Dato* val1, Dato* val2) { //Cambia dos variables
	Dato temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

int partition(vector<Dato> &v, int low, int high) { //Ordena los datos respecto al pivote
	Dato pivot = v[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (v[j] < pivot || v[j] == pivot) {
			i++;
			swap(&v[i], &v[j]);
		}
	}
	swap(&v[i+1], &v[high]);
	return (i+1);
}

void quickSort(vector<Dato> &v, int low, int high) { //Ordenamiento recursivo O(nlog(n))
	if (low < high)
	{
		int pi = partition(v, low, high);
		quickSort(v, low, pi - 1);
		quickSort(v, pi + 1, high);
	}
}

void ordenar(vector<Dato> &vec) {
    quickSort(vec, 0, vec.size()-1);
}

int buscar(vector<Dato> v, Dato val) { //Tiempo O(log(n)) Busqueda binaria
    int l = 0;
    int r = v.size()-1;
    int m; //Declarar apuntadores
    while (l <= r) {
        m = l + (r - l)/2; //La resta evita overflow para valores grandes de l y r
        if (val == v[m] || l == r) return m;
        else if (val < v[m]) r = m-1; //El área de búsqueda se reduce a la mitad
        else l = m+1; 
    }
}

int main() { 
    vector<Dato> v;  // Vector donde se guardan los datos del archivo .txt
    ifstream ifs;
    ifs.open("bitacora.txt");
    string line;
    while(getline(ifs, line)) {
        v.push_back(Dato::leerString(line)); //Se leen y se guardan los datos en el vector
    }
    ordenar(v); //Se ordena el vector
    ifs.close();

    ofstream ofs; // Registra los datos ordenados en salida.txt
    ofs.open("salida.txt");
    for (Dato d : v) ofs << Dato::toString(d);
    ofs.close();

    //Se reciben las entradas y se encuentran sus indices correspondientes
    int diaI, diaF, horaI, horaF, minI, minF, segI, segF;
    string mesI, mesF;
    cout << "Introduzca la fecha y hora iniciales en el formato Mes Dia Horas:Minutos:Segundos" << endl;
    string inputI;
    getline(cin, inputI);
    stringstream ssi;
    ssi << inputI;
    ssi << " 000.00.000.000:0000 Unknown";
    Dato fechaI = Dato::leerString(ssi.str()); //Se genera un dato dummy para comparar
    int indI = buscar(v, fechaI);

    cout << "Introduzca la fecha y hora finales en el formato Mes Dia Horas:Minutos:Segundos" << endl;
    string inputF;
    getline(cin, inputF);
    stringstream ssf;
    ssf << inputF;
    ssf << " 000.00.000.000:0000 Unknown";
    Dato fechaF = Dato::leerString(ssf.str()); //Se genera un dato dummy para comparar
    int indF = buscar(v, fechaF);
    
    //Se imprimen todos los datos entre los indices inicial y final, correspondientes a las entradas
    for (int i=indI; i<=indF; i++) cout << Dato::toString(v[i]);
    cin.get();
    return 0;
} 