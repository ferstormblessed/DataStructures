//Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Sábado 30 de octubre del 2021

#include "Dato.h"
#include "Bst.h"
#include <fstream>
#include <iostream> 
#include <map>

using namespace std;

int main() {
    map<string, int> m; //Mapa donde se guardan las IPs y el número de accesos a cada una
    avl_tree tree; //Arbol AVL
    ifstream ifs;
    ifs.open("entrada copy.txt");
    string line;
    while(getline(ifs, line)) { //Carga las IPs del archivo, guardando su número de accesos en el mapa
        string ip = Dato::leerString(line).getIpShort();
        if (m.find(ip) == m.end()) m[ip] = 1;
        else m[ip]++;
    } 
    ifs.close();
    map<string, int>::iterator it = m.begin();
    avl* root = NULL;
    while (it != m.end()) { //Inserta los datos del mapa en el árbol AVL
        root = tree.insert(root, it->second, it->first);
        it++;
    }
    avl_tree::printTop5(root); //Imprime las 5 IPs con más accesos
    return 0;
} 