#include "Dato.h"
#include <algorithm>

Dato::Dato(string smes, int dia, int hora, int min, int seg, string ip, string razon) {
    mes = mesANumero.at(smes);
    this->smes = smes;
    this->dia = dia;
    this->hora = hora;
    this->min = min;
    this->seg = seg;
    this->ip = ip;
    this->razon = razon;
    ip.erase(remove(ip.begin(), ip.end(), '.'), ip.end()); //Le quita los puntos y el puerto a las Ips
    ipNum = stoll(ip); //Hace la ip un long 
    string resrazon;
    if (razon.find("Illegal user") != string::npos) resrazon = "iu";
    else if (razon.find("Failed password for illegal user") != string::npos) resrazon = "fpiu" + razon.substr(razon.find_last_of(' ')+1);
    else resrazon = "fp" + razon.substr(razon.find_last_of(' ')+1);
    resumen = "m" + to_string(mes) + "d" + to_string(dia) + "h" + to_string(hora) + "n" + to_string(min) + "s" + to_string(seg) + "r" + resrazon;
}

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

string Dato::getResumen() {
    return resumen;
}

long long Dato::getIpNum() {
    return ipNum;
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

string Dato::decodeResumen(string resumen) {
    string mes = resumen.substr(resumen.find('m')+1,resumen.find('d')-resumen.find('m')-1);
    string dia = resumen.substr(resumen.find('d')+1,resumen.find('h')-resumen.find('d')-1);
    string hora = resumen.substr(resumen.find('h')+1,resumen.find('n')-resumen.find('h')-1);
    string min = resumen.substr(resumen.find('n')+1,resumen.find('s')-resumen.find('n')-1);
    string seg = resumen.substr(resumen.find('s')+1,resumen.find('r')-resumen.find('s')-1);
    string resrazon = resumen.substr(resumen.find('r')+1);
    string razon;
    if (resrazon.find("fpiu") != string::npos) razon = "Failed password for illegal user " + resrazon.substr(resumen.find('u')+1);
    else if (resrazon.find("iu") != string::npos) razon = "Illegal user";
    else razon = "Failed password for user " + resrazon.substr(resumen.find('p')+1);
    return mes + "/" + dia + " " + hora + ":" + min + ":" + seg + " " + razon;
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