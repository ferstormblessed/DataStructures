//Act 1.3 Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia) 
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Domingo 12 de septiembre del 2021

#include "Dato.h"
#include <iomanip>

//Getters
int Dato::getMes() {
    return mes;
}

int Dato::getDia() {
    return dia;
}

int Dato::getHora() {
    return hora;
}

int Dato::getMin() {
    return min;
}

int Dato::getSeg() {
    return seg;
}

string Dato::getSMes() {
    return smes;
}

string Dato::getIP() {
    return ip;
}

string Dato::getRazon() {
    return razon;
}

const unordered_map<string,int> Dato::mesANumero {
    {"Jan",1},  //El HashMap hace más eficiente la conversión de string a int, actúa como switch
    {"Feb",2},
    {"Mar",3},
    {"Apr",4}, 
    {"May",5},
    {"Jun",6},
    {"Jul",7},
    {"Aug",8},
    {"Sep",9},
    {"Oct",10},
    {"Nov",11},
    {"Dec",12}
};

Dato::Dato(string smes, int dia, int hora, int min, int seg, string ip, string razon) {
    mes = mesANumero.at(smes);
    this->smes = smes;
    this->dia = dia;
    this->hora = hora;
    this->min = min;
    this->seg = seg;
    this->ip = ip;
    this->razon = razon;
}

Dato Dato::leerString(string st) {
    //Distribuye los valores del string en las variables
    stringstream s;
    s << st;
    string smes, ip, razon, horaLarga;
    int dia, hora, min, seg;
    s >> smes >> dia >> horaLarga >> ip;
    getline(s, razon);

    //Procesa la hora en el formato 00:00:00 a horas, minutos y segundos
    int arrTempInt[3];
    int j = 0;
    char arrTemp[2];
    for(int i=0; i<horaLarga.size(); i++) {
        if (horaLarga[i] == ':') {
            arrTempInt[j++] = stoi(arrTemp);
            char arrTemp[2];
            continue;
        } else arrTemp[i%3] = horaLarga[i];
    }
    arrTempInt[j] = stoi(arrTemp);
    hora = arrTempInt[0];
    min = arrTempInt[1];
    seg = arrTempInt[2];

    //Genera el dato a regresar
    Dato d(smes, dia, hora, min, seg, ip, razon);
    return d;
}

string Dato::toString(Dato d) {
    stringstream s;
    s << d.getSMes() << " " << setw(2) << setfill('0') << d.getDia() << " " //setw y setfill permiten que el formato 
    << setw(2) << setfill('0') << d.getHora() << ":"                        //sea siempre 00:00:00
    << setw(2) << setfill('0') << d.getMin() << ":" 
    << setw(2) << setfill('0') << d.getSeg() << " " << d.getIP() << d.getRazon() << endl;
    return s.str();
}