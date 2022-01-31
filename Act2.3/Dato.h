//Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia) 
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Lunes 11 de octubre del 2021

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
public:
    Dato(string, int, string, string, string); 
    static Dato leerString(string); //Genera Dato a partir de string
    static string toString(Dato); //Convierte todos los atributos de un objeto Dato a string 
                                 //y los regresa en el formato requerido
    int getDia();
    string getHoraLarga();
    string getSMes();
    string getIP();
    string getRazon();
    
    static void swap(Dato* val1, Dato* val2); // Cambia dos variables
    static int partition(vector<Dato> &v, int low, int high); // Ordena los datos respecto al pivote
    static void quickSort(vector<Dato> &v, int low, int high); // Ordenamiento recursivo O(nlog(n))
    static void ordenar(vector<Dato> &vec);
    static int buscar(vector<Dato> v, Dato val); // Tiempo O(log(n)) Busqueda binaria

    //Usamos los operadores <, > y == para la búsqueda y el ordenamiento, por IP
    friend bool operator<(Dato a, Dato b) {
        return a.ipNum < b.ipNum;
    }
    
    friend bool operator>(Dato a, Dato b) {
        return a.ipNum > b.ipNum;
    }

    friend bool operator==(Dato a, Dato b) {
        return a.ip == b.ip;
    }

};
 
#endif 