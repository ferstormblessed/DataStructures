//Act 5.2
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Miércoles 1 de diciembre del 2021

#ifndef DATO_H
#define DATO_H

#include <string>
#include <sstream>
#include <unordered_map>
#include <iomanip>

using namespace std;

class Dato {
private:
    int mes;
    int dia;
    int hora;
    int min;
    int seg;
    long long ipNum;
    string smes;
    string ip;
    string razon;
    string resumen;
public:
    Dato(string, int, int, int, int, string, string); 
    static const unordered_map<string, int> mesANumero;
    static string decodeResumen(string);
    static Dato leerString(string); //Genera Dato a partir de string
    static string toString(Dato); //Convierte todos los atributos de un objeto Dato a string 
    int getMes();                 //y los regresa en el formato requerido
    int getDia();
    int getHora();
    int getMin();
    int getSeg();
    string getSMes();
    string getIP();
    string getRazon();
    string getResumen();
    long long getIpNum();
};

#endif 