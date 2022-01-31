//Act 1.3 Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia) 
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Domingo 12 de spetiembre del 2021

#ifndef DATO_H
#define DATO_H

#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Dato {
private:
    int mes;
    int dia;
    int hora;
    int min;
    int seg;
    string smes;
    string ip;
    string razon;
public:
    Dato(string, int, int, int, int, string, string); 
    static const unordered_map<string, int> mesANumero;
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

    //Usamos los operadores <, > y == para la búsqueda y el ordenamiento, por fecha y hora
    friend bool operator<(Dato a, Dato b) {
        if (a.mes < b.mes) return true;
        else if (a.mes > b.mes) return false;
        else {
            if (a.dia < b.dia) return true;
            else if (a.dia > b.dia) return false;
            else {
                if (a.hora < b.hora) return true;
                else if (a.hora > b.hora) return false;
                else { 
                    if (a.min < b.min) return true;
                    else if (a.min > b.min) return false;
                    else {
                        if (a.seg < b.seg) return true;
                        else return false;
                    }
                }
            }
        }
    }
    
    friend bool operator>(Dato a, Dato b) {
        if (a.mes > b.mes) return true;
        else if (a.mes < b.mes) return false;
        else {
            if (a.dia > b.dia) return true;
            else if (a.dia < b.dia) return false;
            else {
                if (a.hora > b.hora) return true;
                else if (a.hora < b.hora) return false;
                else { 
                    if (a.min > b.min) return true;
                    else if (a.min < b.min) return false;
                    else {
                        if (a.seg > b.seg) return true;
                        else return false;
                    }
                }
            }
        }
    }
    //Solo es igual si la fecha y hora son iguales
    friend bool operator==(Dato a, Dato b) {
        if (a.mes == b.mes && a.dia == b.dia && 
        a.hora == b.hora && a.min == b.min && a.seg == b.seg) return true;
        else return false;
    }
};
 
#endif 