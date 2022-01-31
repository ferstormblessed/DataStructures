//Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia) 
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Lunes 11 de octubre del 2021

#include "Dato.h"
#include <iomanip>

using namespace std;

//Getters

int Dato::getDia() {
    return dia;
}

string Dato::getSMes() {
    return smes;
}

string Dato::getHoraLarga(){
    return horaLarga;
}

string Dato::getIP() {
    return ip;
}

string Dato::getRazon() {
    return razon;
}

Dato::Dato(string smes, int dia, string horaLarga, string ip, string razon) {
    this->smes = smes;
    this->dia = dia;
    this->horaLarga = horaLarga;
    this->ip = ip;
    this->razon = razon;
    string temp = ip;
    vector<string> v;
    for (int i=0; i<4; i++) { //Parsing de la IP 
        string token = temp.substr(0, temp.find("."));
        temp.erase(0, temp.find(".") + 1); 
        v.push_back(token);
    }
    v[0].insert(0,string(3-v[0].size(),'0')); //Agrega los 0s faltantes
    v[1].insert(0,string(2-v[1].size(),'0'));
    v[2].insert(0,string(3-v[2].size(),'0'));
    v[3].insert(0,string(8-v[3].size(),'0'));
    temp = v[0]+v[1]+v[2]+v[3];
    ipNum = stoll(temp); //Transforma la IP en numero para poder ser comparada
}

Dato Dato::leerString(string st) {
    //Distribuye los valores del string en las variables
    stringstream s;
    s << st;
    string smes, ip, razon, horaLarga;
    int dia, hora, min, seg;
    s >> smes >> dia >> horaLarga >> ip;
    getline(s, razon);
    //Genera el dato a regresar
    Dato d(smes, dia, horaLarga, ip, razon);
    return d;
}

string Dato::toString(Dato d) {
    stringstream s;
    s << d.getSMes() << " " << setw(2) << setfill('0') << d.getDia() << " " //setw y setfill permiten que el formato 
    << d.getHoraLarga() << " " << d.getIP() << d.getRazon() << endl;
    return s.str();
}

void Dato::swap(Dato* val1, Dato* val2) { //Cambia dos variables
	Dato temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

int Dato::partition(vector<Dato> &v, int low, int high) { //Ordena los datos respecto al pivote
	Dato pivot = v[high];
	int i = low-1;

	for (int j = low; j <= high - 1; j++) {
		if (v[j] < pivot || v[j] == pivot) {
			i++;
			swap(&v[i], &v[j]);
		}
	}
	Dato::swap(&v[i+1], &v[high]);
	return (i+1);
}

void Dato::quickSort(vector<Dato> &v, int low, int high) { //Ordenamiento recursivo O(nlog(n))
	if (low < high)
	{
		int pi = Dato::partition(v, low, high);
		quickSort(v, low, pi - 1);
		quickSort(v, pi + 1, high);
	}
}

void Dato::ordenar(vector<Dato> &vec) {
    Dato::quickSort(vec, 0, vec.size()-1);
}

int Dato::buscar(vector<Dato> v, Dato val) { //Tiempo O(log(n)) Busqueda binaria
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
