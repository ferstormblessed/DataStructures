//Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Sábado 30 de octubre del 2021

#ifndef DATO_H
#define DATO_H

#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Dato {
private:
    int mes;
    int dia;
    long long ipNum; //IP como numero
    string horaLarga;
    string smes;
    string ip;
    string razon;
    string ipShort;
public:
    Dato(string, int, string, string, string); 
    static Dato leerString(string); //Genera Dato a partir de string
    int getDia();
    string getHoraLarga();
    string getSMes();
    string getIP();
    string getIpShort();
    string getRazon();
};
 
#endif 