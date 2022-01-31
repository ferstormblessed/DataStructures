//Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Sábado 30 de octubre del 2021

#include "Dato.h"
#include <iomanip>

using namespace std;
Dato::Dato(string smes, int dia, string horaLarga, string ip, string razon) {
    this->smes = smes;
    this->dia = dia;
    this->horaLarga = horaLarga;
    this->ip = ip;
    this->ipShort = ip.substr(0, ip.find(":"));
    this->razon = razon;
    string temp = ipShort;
    vector<string> v;
    for (int i=0; i<4; i++) { //Parsing de la IP 
        string token = temp.substr(0, temp.find("."));
        temp.erase(0, temp.find(".") + 1); 
        v.push_back(token);
    }
    v[0].insert(0,string(3-v[0].size(),'0')); //Agrega los 0s faltantes
    v[1].insert(0,string(2-v[1].size(),'0'));
    v[2].insert(0,string(3-v[2].size(),'0'));
    v[3].insert(0,string(3-v[3].size(),'0'));
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

string Dato::getIpShort() {
    return ipShort;
}

string Dato::getRazon() {
    return razon;
}